#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

// Graph Representation

// 1-> Graphs are represented using Adjacency list and matrix
// In this lecture we are going to represent graph using Adjacency list

// bUILDING A GRAPH USING ADJACENCY LIST

class Graph
{
    int V;
    list<pair<int, int>> *l;

public:
    Graph(int V = 5)
    {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w = 1)
    {
        l[u].push_back({v, w});
        l[v].push_back({u, w});
    }

    void Print()
    {
        for (int i = 0; i < V; i++)
        {
            const list<pair<int, int>> &neighbours = l[i];
            cout << i << " : ";
            for (const auto &v : neighbours)
            {
                cout << "(" << v.first << ", weight= " << v.second << "), ";
            }
            cout << endl;
        }
    }

   
};

int main()
{
    Graph graph;

    graph.addEdge(0, 1, 2);
    graph.addEdge(1, 2, 4);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 6);
    graph.Print();
}
