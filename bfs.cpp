#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

// Serial BFS implementation
void bfs_serial(const std::vector<std::vector<int>>& graph, int start) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph
    std::vector<std::vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1, 5},
        {1, 2, 5},
        {3, 4}
    };

    std::cout << "Serial BFS starting from node 0: ";

    auto start = std::chrono::high_resolution_clock::now();
    bfs_serial(graph, 0);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << std::endl;

    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}
