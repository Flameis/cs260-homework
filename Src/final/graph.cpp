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
private:
    vector<pair<char, vector<Edge>>> vertices;

public:
    // Add a vertex to the graph
    void add_vertex(char vertex) {
        // If the vertex is not already in the graph, add it
        for (auto& v : vertices) {
            if (v.first == vertex) {
                return; // Vertex already exists
            }
        }
        // Add the vertex to the graph
        vertices.emplace_back(vertex, vector<Edge>());
    }

    // Add an edge to the graph
    void add_edge(char source, char destination, int weight = 1) {
        // Add the edge to the source vertex
        for (auto& v : vertices) {
            // Find the source vertex
            if (v.first == source) {
                v.second.push_back({destination, weight});
            } else if (v.first == destination) {
                v.second.push_back({source, weight});
            }
        }
    }

    // Print the graph
    void print() {
        // Print the vertices and edges
        for (const auto& vertex : vertices) {
            cout << vertex.first << " -> ";
            for (const auto& edge : vertex.second) {
                cout << "(" << edge.destination << ", " << edge.weight << ") ";
            }
            cout << endl;
        }
    }

    // Find the shortest path between two vertices
    pair<int, vector<char>> shortest_path(char source, char destination) {
        // Initialize distances, parent, and visited vectors
        vector<int> distances(vertices.size(), INT_MAX);
        vector<char> parent(vertices.size(), 0);
        vector<bool> visited(vertices.size(), false);

        int sourceIndex = -1, destinationIndex = -1;
        // Iterate through the vertices to find the indices
        for (size_t i = 0; i < vertices.size(); ++i) {
            if (vertices[i].first == source) {
                sourceIndex = i;
            } else if (vertices[i].first == destination) {
                destinationIndex = i;
            }
        }

        distances[sourceIndex] = 0;

        // Create a priority queue to hold pairs of (distance, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, sourceIndex});

        // Dijkstra's algorithm
        while (!pq.empty()) {
            int current_distance = pq.top().first;
            int current_index = pq.top().second;
            pq.pop();

            // If the current distance is greater than the known distance, skip
            if (visited[current_index]) {
                continue;
            }
            visited[current_index] = true;

            // Iterate through the neighbors of the current vertex
            for (const auto& edge : vertices[current_index].second) {
                int neighbor_index = -1;
                // Find the index of the neighbor vertex
                for (size_t i = 0; i < vertices.size(); ++i) {
                    if (vertices[i].first == edge.destination) {
                        neighbor_index = i;
                        break;
                    }
                }
                // Calculate the distance to the neighbor
                int distance = current_distance + edge.weight;
                if (distance < distances[neighbor_index]) {
                    distances[neighbor_index] = distance;
                    parent[neighbor_index] = current_index;
                    pq.push({distance, neighbor_index});
                }
            }
        }

        // Reconstruct the shortest path
        int shortest_distance = distances[destinationIndex];
        vector<char> path;
        int current = destinationIndex;
        // Reconstruct the path from the destination to the source
        while (current != sourceIndex) {
            path.push_back(vertices[current].first);
            current = parent[current];
        }
        // Add the source vertex to the path
        path.push_back(vertices[sourceIndex].first);

        // Reverse the path to get the correct order
        reverse(path.begin(), path.end());

        // Return the shortest distance and path
        return {shortest_distance, path};
    }

    // Find the minimum spanning tree of the graph
    vector<vector<pair<char, int>>> min_span_tree() {
        // Initialize visited and min_span_tree vectors
        vector<bool> visited(vertices.size(), false);
        vector<vector<pair<char, int>>> min_span_tree(vertices.size());

        // Create a priority queue to hold pairs of (weight, (prev_vertex, current_vertex))
        priority_queue<pair<int, pair<char, char>>, vector<pair<int, pair<char, char>>>, greater<pair<int, pair<char, char>>>> pq;
        pq.push({0, {'\0', vertices[0].first}});

        // Prim's algorithm
        while (!pq.empty()) {
            // Get the edge with the smallest weight
            int weight = pq.top().first;
            char prev_vertex = pq.top().second.first;
            char current_vertex = pq.top().second.second;
            pq.pop();

            // If the current vertex has been visited, skip
            if (visited[current_vertex - 'A']) {
                continue;
            }

            // Mark the current vertex as visited
            visited[current_vertex - 'A'] = true;

            // Add the edge to the minimum spanning tree (if not root)
            if (prev_vertex != '\0') {
                min_span_tree[prev_vertex - 'A'].push_back({current_vertex, weight});
                min_span_tree[current_vertex - 'A'].push_back({prev_vertex, weight});
            }

            // Iterate through the neighbors of the current vertex
            for (const auto& edge : vertices[current_vertex - 'A'].second) {
                if (!visited[edge.destination - 'A']) {
                    pq.push({edge.weight, {current_vertex, edge.destination}});
                }
            }
        }

        // Return the minimum spanning tree
        return min_span_tree;
    }
};

int main() {
    Graph graph;
    // Add vertices and edges to the graph
    graph.add_vertex('A');
    graph.add_vertex('B');
    graph.add_vertex('C');
    graph.add_vertex('D');

    graph.add_edge('A', 'B', 2);
    graph.add_edge('A', 'C', 1);
    graph.add_edge('B', 'C', 3);
    graph.add_edge('B', 'D', 4);
    graph.add_edge('C', 'D', 5);

    // Log the vertices and edges
    graph.print();

    // Log expected output
    cout << "Expected output:" << endl;
    cout << "A -> (B, 2) (C, 1) " << endl;
    cout << "B -> (A, 2) (C, 3) (D, 4) " << endl;
    cout << "C -> (A, 1) (B, 3) (D, 5) " << endl;
    cout << "D -> (B, 4) (C, 5) " << endl;

    // Test shortest path algorithm
    auto [shortest_distance, shortest_path] = graph.shortest_path('A', 'D');
    cout << "Shortest distance from A to D: " << shortest_distance << endl;
    cout << "Shortest path from A to D: ";
    for (char vertex : shortest_path) {
        cout << vertex << " ";
    }
    cout << endl;

    // Log expected output
    cout << "Expected output:" << endl;
    cout << "Shortest distance from A to D: 6" << endl;
    cout << "Shortest path from A to D: A C D " << endl;

    // Test minimum spanning tree algorithm
    auto min_span_tree = graph.min_span_tree();
    cout << "Minimum Spanning Tree:" << endl;
    for (size_t i = 0; i < min_span_tree.size(); ++i) {
        cout << char('A' + i) << " -> ";
        for (const auto& neighbor : min_span_tree[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }

    // Log expected output
    cout << "Expected output:" << endl;
    cout << "Minimum Spanning Tree:" << endl;
    cout << "A -> (C, 1) (B, 2) " << endl;
    cout << "B -> (A, 2) (D, 4) " << endl;
    cout << "C -> (A, 1) " << endl;
    cout << "D -> (B, 4) " << endl;

    return 0;
}
