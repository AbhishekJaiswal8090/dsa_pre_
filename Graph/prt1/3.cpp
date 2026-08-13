#include <iostream>
#include <queue>
#include <vector>
#include <list>

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
            cout << i << ": ";
            list<int> &neighbours = l[i];
            for (int x : neighbours)
            {
                cout << " " << x << " ";
            }
            cout << endl;
        }
    }

    void BFS()
    {

        vector<bool> vis(V, false);
        queue<int> q;

        vis[0] = true;
        q.push(0);

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

    void DFSHelper(int u, vector<bool> &vis)
    {

        cout << u << " ";
        vis[u] = true;

        list<int> &neighbours = l[u];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                DFSHelper(v, vis);
            }
        }
    }
    void DFS()
    {
        vector<bool> vis(V, false);
        DFSHelper(0, vis);
        cout << endl;
    }

    bool HashPathHelper(int src, int des, vector<bool> &vis)
    {

        if (src == des)
        {
            return true;
        }
        vis[src] = true;
        list<int> &neighbours = l[src];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                if (HashPathHelper(v, des, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool HashPath()
    {
        vector<bool> vis(V, false);
        return HashPathHelper(0, 4, vis);
    }
};

int main()
{
    Graph graph;

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.Print();
    graph.BFS();
    cout << endl;
    graph.DFS();

    cout << graph.HashPath();
}