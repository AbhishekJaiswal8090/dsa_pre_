#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

// In this lecture we are going to find a way to detect cycles ina an graph
// so there are multiple way but at first we are going to discuss parent tracking method
// this methods deals is that we will contiue to traverse the node and tracks the parent node
// and during traversing once we find out that the current node neigbour is already visited
// even though the parent of current node is diff from the already vis neigbour so that simply means we have found an cycle in undirected graph

class Graph
{
    int V;
    list<int> *l;
    bool unDir;

public:
    Graph(int V = 5, bool unDir = true)
    {
        this->V = V;
        l = new list<int>[V];
        this->unDir = unDir;
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        if (unDir)
        {
            l[v].push_back(u);
        }
    }

    bool Helper(int src, int par, vector<bool> &vis)
    {
        vis[src] = true;
        list<int> &neighbours = l[src];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                if (Helper(v, src, vis))
                {
                    return true;
                }
            }
            else
            {
                if (v != par) // neighbour is not parent but already visited => cycle detected
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool undirectedCycleDetection()
    {
        vector<bool> vis(V, false);
        return Helper(0, -1, vis);
    }

    // In an Directed graph the process is diff to find an cycle
    // since directed node always specifies the direction we can move
    // This methode is called Recursion path tracking
    // we will keep reacking recursion path of each node and once we found that
    // we are at node which is already ben in to the recursion path that means we have detected cycle

    bool Helper_2(vector<bool> &vis, vector<bool> &recPath, int src)
    {
        vis[src] = true;
        recPath[src] = true;
        list<int> &neighbours = l[src];
        for (int v : neighbours)
        {
            if (!vis[v])
            {
                if (Helper_2(vis, recPath, v))
                {
                    return true;
                }
            }
            else
            {
                if (recPath[v])
                {
                    return true;
                }
            }
        }
    }

    bool directedCycleDetection()
    {
        vector<bool> vis(V, false);
        vector<bool> recPath(V, false);
        for (int i = 0; i < V; i++)
        {

            if (!vis[i])
            {
                if (Helper_2(vis, recPath, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isBipartite()
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (q.size() > 0)
                {
                    int curr = q.front();
                    q.pop();
                    list<int> &neighbours = l[curr];
                    for (int v : neighbours)
                    {
                        if (color[v] == -1)
                        {
                            color[v] = 1 - color[curr];
                            q.push(v);
                        }
                        else
                        {
                            if (color[v] == color[curr])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    void Helper_3(vector<vector<int>> &ans, int src, int dest, vector<int> &path)
    {
        vis[src] = true;
        path.push_back(src);

        if (src == dest)
        {
            ans.push_back(path);
        }
        else
        {
            for (int v : l[src])
            {
                if (!vis[v])
                {
                    Helper_3(ans, v, dest, path);
                }
            }
        }

        path.pop_back();

        vis[src] = false;
    }

    vector<vector<int>> allPathProblem(int src, int dest)
    {
        vector<vector<int>> ans;
        vector<int> path;
        Helper_3(ans, src, dest, path);
        return ans;
    }
};

int main()
{

    Graph graph(4, true);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    // cout << graph.undirectedCycleDetection() << endl;
    // cout << graph.directedCycleDetection() << endl;

    cout << graph.isBipartite();
}