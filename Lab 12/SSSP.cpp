
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int vertex;
    int weight;
};

vector<int> dijkstra(vector<vector<Node>>& graph, int source) {
    int V = graph.size();
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    // Priority queue to store nodes to be visited (min-heap based on distance)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_dist > distance[current_node])
            continue;

        for (Node neighbor : graph[current_node]) {
            int v = neighbor.vertex;
            int weight = neighbor.weight;

            int new_dist = current_dist + weight;
            if (new_dist < distance[v]) {
                distance[v] = new_dist;
                pq.push(make_pair(new_dist, v));
            }
        }
    }

    return distance;
}

int main() {
    int V = 6;  // Number of vertices

    vector<vector<Node>> graph(V);

    // Add edges and weights to the graph
    graph[0].push_back({1, 10});
    graph[1].push_back({0, 10});
    graph[0].push_back({5, 5});
    graph[5].push_back({0, 5});
    graph[0].push_back({4, 15});
    graph[4].push_back({0, 15});
    graph[4].push_back({2, 5});
    graph[2].push_back({4, 5});
    graph[5].push_back({3, 20});
    graph[3].push_back({5, 20});
    graph[3].push_back({2, 12});
    graph[2].push_back({3, 12});
    graph[1].push_back({2, 10});
    graph[2].push_back({1, 10});
    graph[1].push_back({3, 30});
    graph[3].push_back({1, 30});
  
    // Source city can be changed by changint the value below
    int source = 0;

    vector<int> shortest_distances = dijkstra(graph, source);

    cout << "Shortest time from Source City(City " << source << ") to all other cities:\n";
    for (int i = 0; i < V; i++) {
        cout << "Shortest time from City " << source << " to City " << i << ": ";
        if (shortest_distances[i] == INT_MAX)
            cout << "No path";
        else
            cout << shortest_distances[i];
        cout << "\n";
    }

    return 0;
}


