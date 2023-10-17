#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <functional>
#include <limits>

// this is a sketch - helped by my llm, but will be updated to a better implementation tomorrow.

template <typename T, typename Weight = int>
class Graph {
public:
    Graph() {}

    void Dijkstra(
        const T& start, 
        std::function<std::vector<std::pair<T, Weight>>(const T&)> getNeighbors,
        std::function<bool(const T&)> isTerminal
    ) {
        std::unordered_map<T, Weight> distance; // Store distance from start to each vertex
        Weight upperBound = std::numeric_limits<Weight>::max();

        using Pair = std::pair<Weight, T>; // (distance, vertex)
        std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> minHeap; // Min heap

        distance[start] = Weight(); // Default construct weight (0 for numeric types)
        minHeap.push({Weight(), start});

        while (!minHeap.empty()) {
            T current = minHeap.top().second;
            Weight currentDistance = minHeap.top().first;
            minHeap.pop();

            // Check if the dequeued distance matches the current shortest known distance
            if (currentDistance != distance[current]) continue;

            // If currentDistance is already greater than upperBound, no need to continue
            if (currentDistance > upperBound) continue;

            std::cout << "Vertex: " << current << ", Distance: " << currentDistance << std::endl;

            // If current vertex is terminal, update the upper bound if necessary
            if (isTerminal(current) && currentDistance < upperBound) {
                upperBound = currentDistance;
                std::cout << "Found terminal vertex: " << current << ", updating upper bound to: " << upperBound << std::endl;
            }

            for (const auto& pair : getNeighbors(current)) {
                const T& neighbor = pair.first;
                Weight edgeWeight = pair.second;

                if (
                    distance.find(neighbor) == distance.end() || 
                    currentDistance + edgeWeight < distance[neighbor]
                ) {
                    distance[neighbor] = currentDistance + edgeWeight;
                    minHeap.push({distance[neighbor], neighbor});
                }
            }
        }
    }

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
