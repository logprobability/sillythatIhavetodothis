#include <iostream>
#include <unordered_map>
#include <queue>
#include <functional>

template <typename T>
class Graph {
public:
    Graph() {}

    void BFS(const T& start, std::function<std::vector<T>(const T&)> getNeighbors) {
        std::unordered_map<T, bool> visited;
        std::queue<T> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            T current = queue.front();
            queue.pop();

            std::cout << current << " ";

            for (const T& neighbor : getNeighbors(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a graph
    Graph<int> g;

    // Define a function to get neighbors for each vertex
    auto getNeighborsFunc = [](const int& vertex) -> std::vector<int> {
        std::vector<int> neighbors;

        // Define your logic to get neighbors here
        // For example, hardcoding neighbors for demonstration:
        if (vertex == 0) {
            neighbors.push_back(1);
            neighbors.push_back(2);
        } else if (vertex == 1) {
            neighbors.push_back(3);
            neighbors.push_back(4);
        } else if (vertex == 2) {
            neighbors.push_back(5);
            neighbors.push_back(6);
        }

        return neighbors;
    };

    std::cout << "Breadth-First Traversal starting from vertex 0: ";
    g.BFS(0, getNeighborsFunc);

    return 0;
}
