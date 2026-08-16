#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <climits>

using namespace std;

// In this lecture we are going to study about Bellman Ford algorithm
// The problem that could not solved using Dijkstra could be solved by this algorithm
// Dijkstra couldn't handle the negative weights while bellman ford efficiently handle
// but with trading off time complexity
// Dijkstra normal takes o(V+E) while this take O(V*E) coulde be said o(V)2

class EdgeList
{
public:
    int v;
    int wt;
    EdgeList(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(vector<vector<EdgeList>> graph, int src, int v)
{
    vector<int> dis(v, INT_MAX);
    dis[src] = 0;

    for (int i = 0; i < v; i++)
    {
        for (int u = 0; u < v; u++)
        {

            for (const EdgeList &e : graph[u])
            {
                if (dis[e.v] > dis[u] + e.wt)
                {
                    dis[e.v] = dis[u] + e.wt;
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

int main()
{
    int V = 6;
    vector<vector<EdgeList>> graph(V);

    graph[0].push_back(EdgeList(1, 2));
    graph[0].push_back(EdgeList(2, 4));

    graph[1].push_back(EdgeList(2, 1));
    graph[1].push_back(EdgeList(3, 7));

    graph[2].push_back(EdgeList(4, 3));

    graph[3].push_back(EdgeList(5, 1));

    graph[4].push_back(EdgeList(3, 2));
    graph[4].push_back(EdgeList(2, 5));

    bellmanFord(graph, 0, V);
    return 0;
}