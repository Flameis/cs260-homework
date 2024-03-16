#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Edge {
    char destination;
    int weight;
};

class Graph {
public:
    vector<pair<char, vector<Edge>>> vertices;

    // Add a vertex to the graph
    void add_vertex(char vertex)

    // Add an edge to the graph
    void add_edge(char source, char destination, int weight = 1)

    // Print the graph
    void print()

    // Find the shortest path between two vertices
    pair<int, vector<char>> shortest_path(char source, char destination)

    // Find the minimum spanning tree of the graph
    vector<vector<pair<char, int>>> min_span_tree()
};