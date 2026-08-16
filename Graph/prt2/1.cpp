#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Edgelist
{
public:
    int v;
    int wt;

    Edgelist(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstraAlgom(vector<vector<Edgelist>> graph, int src, int V)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // pair(dis[[v],v]);
    vector<int> dis(V, INT_MAX);

    pq.push(make_pair(0, src));
    dis[src] = 0;

    while (pq.size() > 0)
    {
        int u = pq.top().second;
        pq.pop();

        vector<Edgelist> edges = graph[u];
        for (Edgelist e : edges)
        {
            if (dis[e.v] > dis[u] + e.wt)
            {
                dis[e.v] = dis[u] + e.wt;
                pq.push(make_pair(dis[e.v], e.v));
            }
        }
    }

    for (int d : dis)
    {
        cout << d << " ";
    }
    cout << endl;
}

int main()
{
    int V = 6;
    vector<vector<Edgelist>> graph(V);
    graph[0].push_back(Edgelist(1, 2));
    graph[0].push_back(Edgelist(2, 4));

    graph[1].push_back(Edgelist(2, 1));
    graph[1].push_back(Edgelist(3, 7));

    graph[2].push_back(Edgelist(4, 3));

    graph[3].push_back(Edgelist(5, 1));

    graph[4].push_back(Edgelist(3, 2));
    graph[4].push_back(Edgelist(2, 5));

    dijkstraAlgom(graph, 0, V);
}