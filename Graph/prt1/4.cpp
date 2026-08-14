#include <iostream>
#include <list>
#include <vector>
#include <queue>

// BFS and DFS algorithm for diconnected component of graph;

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V = 5)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void Print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            list<int> &neighbours = l[i];
            for (int v : neighbours)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void bfsHelper(int u, vector<bool> &vis)
    {
        queue<int> q;
        q.push(u);
        vis[u] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";
            list<int> &neighbours = l[u];
            for (int v : neighbours)
            {
                if (!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void BFS()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {

                bfsHelper(i, vis);
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
        list<int> &neighbours = l[u];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                dfsHelper(v, vis);
            }
        }
    }

    void DFS()
    {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsHelper(i, vis);
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph graph;

    graph.addEdge(0, 1);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.Print();
    graph.BFS();
    cout << endl;

    graph.DFS();
}