// bellman ford algorithm
// shortest path

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    // source, destination, weight
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;

    Graph(int vertices, int edges);
    void addEdge(int src, int dest, int weight);
    void BellmanFord(int src);
};

// constructor
Graph::Graph(int vertices, int edges) {
    V = vertices;
    E = edges;
}

// add edge to graph
void Graph::addEdge(int src, int dest, int weight) {
    edges.push_back({ src, dest, weight });
}

// bellman ford algorithm
void Graph::BellmanFord(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (const auto& edge : edges) {
        int u = edge.src;
        int v = edge.dest;
        int w = edge.weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "graph contains negative-weight cycle\n";
            return;
        }

    }

    // print distances
    cout << "vertex\tdistance from source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}



int main()
{
    int V, E;
    cout << "enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V, E);
    cout << "enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src;
        int dest;
        int weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    int src;
    cout << "enter the source vertex: ";
    cin >> src;

    graph.BellmanFord(src);

    return 0;

}
