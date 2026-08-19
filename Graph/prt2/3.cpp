#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <list>
using namespace std;

// In today lecture we are going to study about MST
// so first of all an spanning tree is an subgraph of graph g wihtout containing any cycles forming a tree
// while MST is the minimum edge wieght take during building an spanning tree thats it
// the prims algorithm is an Greedy algorithm which works greedily by chossing one optimal answer at at time and at last it builds globally optimal


class Graph
{
    int V;
    list<pair<int, int>> *l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt)
    {
        l[u].push_back(make_pair(v, wt));
        if (isUndir)
        {
            l[v].push_back(make_pair(u, wt));
        }
    }

    void PrimsAlgo(int size)
    {
        vector<bool> MST(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        int ans = 0;

        while (pq.size() > 0)
        {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (!MST[u])
            {
                MST[u] = true;
                ans += wt;
                list<pair<int, int>> &neighbours = l[u];
                for (pair<int, int> &n : neighbours)
                {
                    pq.push(make_pair(n.second, n.first));
                }
            }
        }

        cout << "The total edge weight of the MST is " << ans << endl;
    }
};

int main()
{
    // Create a graph with 6 vertices (0-5), undirected graph
    Graph g(6, true);

    // Add edges: addEdge(u, v, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);

    // Run Prim's algorithm starting from vertex 0
    g.PrimsAlgo(0);

    return 0;
}