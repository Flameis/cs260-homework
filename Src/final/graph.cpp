#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

// Custom structure to represent coordinates
struct Coordinate {
    int x;
    int y;

    Coordinate(int _x, int _y) : x(_x), y(_y) {}
};

class Graph {
public:
    void addVertex(Coordinate vertex);
    void addEdge(Coordinate source, Coordinate destination, int weight);
    vector<Coordinate> shortestPath(Coordinate source, Coordinate destination);
    vector<pair<Coordinate, Coordinate>> minSpanTree();

private:
    unordered_map<Coordinate, vector<pair<Coordinate, int>>> adjacencyList;
};

void Graph::addVertex(Coordinate vertex) {
    if (adjacencyList.find(vertex) == adjacencyList.end()) {
        adjacencyList[vertex] = {};
    }
}

void Graph::addEdge(Coordinate source, Coordinate destination, int weight) {
    addVertex(source);
    addVertex(destination);
    adjacencyList[source].push_back({destination, weight});
    adjacencyList[destination].push_back({source, weight});
}

vector<Coordinate> Graph::shortestPath(Coordinate source, Coordinate destination) {
    // Implement shortest path algorithm (e.g., Dijkstra's algorithm)
    unordered_map<Coordinate, int> distance;
    unordered_map<Coordinate, Coordinate> previous;
    priority_queue<pair<int, Coordinate>, vector<pair<int, Coordinate>>, greater<pair<int, Coordinate>>> pq;

    for (const auto& vertex : adjacencyList) {
        distance[vertex.first] = numeric_limits<int>::max();
        previous[vertex.first] = Coordinate(-1, -1);
    }

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        Coordinate current = pq.top().second;
        pq.pop();

        if (current.x == destination.x && current.y == destination.y) {
            break;
        }

        for (const auto& neighbor : adjacencyList[current]) {
            Coordinate next = neighbor.first;
            int weight = neighbor.second;

            int newDistance = distance[current] + weight;
            if (newDistance < distance[next]) {
                distance[next] = newDistance;
                previous[next] = current;
                pq.push({newDistance, next});
            }
        }
    }

    vector<Coordinate> path;
    Coordinate current = destination;
    while (current.x != -1 && current.y != -1) {
        path.push_back(current);
        current = previous[current];
    }
    reverse(path.begin(), path.end());

    return path;
}

vector<pair<Coordinate, Coordinate>> Graph::minSpanTree() {
    // Implement minimum spanning tree algorithm (e.g., Prim's algorithm)
    vector<pair<Coordinate, Coordinate>> minSpanningTree;
    unordered_map<Coordinate, bool> visited;
    priority_queue<pair<int, pair<Coordinate, Coordinate>>, vector<pair<int, pair<Coordinate, Coordinate>>>, greater<pair<int, pair<Coordinate, Coordinate>>>> pq;

    for (const auto& vertex : adjacencyList) {
        visited[vertex.first] = false;
    }

    visited.begin()->second = true;

    for (const auto& neighbor : adjacencyList[visited.begin()->first]) {
        pq.push({neighbor.second, {visited.begin()->first, neighbor.first}});
    }

    while (!pq.empty()) {
        Coordinate source = pq.top().second.first;
        Coordinate destination = pq.top().second.second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[destination]) {
            continue;
        }

        visited[destination] = true;
        minSpanningTree.push_back({source, destination});

        for (const auto& neighbor : adjacencyList[destination]) {
            if (!visited[neighbor.first]) {
                pq.push({neighbor.second, {destination, neighbor.first}});
            }
        }
    }

    return minSpanningTree;
}

int main()
{
    Graph graph;

    // Test adding vertices
    graph.addVertex(Coordinate(0, 0));
    graph.addVertex(Coordinate(1, 1));
    graph.addVertex(Coordinate(2, 2));
    graph.addVertex(Coordinate(3, 3));
    graph.addVertex(Coordinate(4, 4));

    // Test adding edges
    graph.addEdge(Coordinate(0, 0), Coordinate(1, 1), 2);
    graph.addEdge(Coordinate(0, 0), Coordinate(2, 2), 1);
    graph.addEdge(Coordinate(1, 1), Coordinate(3, 3), 3);
    graph.addEdge(Coordinate(2, 2), Coordinate(3, 3), 4);
    graph.addEdge(Coordinate(2, 2), Coordinate(4, 4), 5);
    graph.addEdge(Coordinate(3, 3), Coordinate(4, 4), 6);

    // Test shortest path
    vector<Coordinate> shortestPathAC = graph.shortestPath(Coordinate(0, 0), Coordinate(4, 4));
    cout << "Shortest path from (0, 0) to (4, 4): ";
    for (const auto& vertex : shortestPathAC) {
        cout << "(" << vertex.x << ", " << vertex.y << ") ";
    }
    cout << endl;

    // Test minimum spanning tree
    vector<pair<Coordinate, Coordinate>> minSpanTree = graph.minSpanTree();
    cout << "Minimum spanning tree: ";
    for (const auto& edge : minSpanTree) {
        cout << "(" << edge.first.x << ", " << edge.first.y << ") -> (" << edge.second.x << ", " << edge.second.y << ") ";
    }
    cout << endl;

    return 0;
}
