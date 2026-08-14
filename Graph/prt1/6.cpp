#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>

using namespace std;

// Now we are going to deal with the Topogical sort
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
            cout << val << " ";
            st.pop();
        }
    }
};

int main()
{

    Graph graph(6, false);
    graph.addEdge(0, 2);
    graph.addEdge(0, 5);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 5);
    graph.addEdge(4, 1);

    graph.topoLogicalSort();
}