#include <iostream>
#include <vector>
#include <queue>
#include <stack >
#include <list>
#include <queue>
using namespace std;

// In this lectute we are going to study KAHNS Algorithm

class Graph
{
    int V;
    list<int> *l;
    bool isUnDir;

public:
    Graph(int V = 5, bool isUnDir = true)
    {
        this->V = V;
        this->isUnDir = isUnDir;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        if (isUnDir)
            l[v].push_back(u);
    }

    void Helper(vector<bool> &vis, stack<int> &stack, int src)
    {
        vis[src] = true;
        list<int> &neighbours = l[src];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                Helper(vis, stack, v);
            }
        }
        stack.push(src);
    }

    void topoLogicalSort()
    {
        vector<bool> vis(V);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                Helper(vis, st, i);
            }
        }

        while (st.size())
        {
            int val = st.top();
            cout << val << " ";-
            st.pop();
        }
    }

    void calculateIndegree(vector<int> &indegree)
    {
        for (int i = 0; i < V; i++)
        {
            list<int> &neighbours = l[i];
            for (int v : neighbours)
            {
                indegree[v]++;
            }
        }
    }

    void kahnsAlgo()
    {
        vector<int> indegree(V, 0);
        calculateIndegree(indegree);

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            list<int> &neighbours = l[curr];
            for (int v : neighbours)
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }
};

// Toplogical sort using Kahn;s algorthm
// first of all we meed to calculate the indegree of each and every node

int main()
{
    Graph graph(6, false);
    graph.addEdge(4, 0);
    graph.addEdge(4, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(3, 1);
    graph.addEdge(5, 1);
    graph.addEdge(5, 0);

    graph.kahnsAlgo();
}