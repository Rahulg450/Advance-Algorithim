#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

struct MyEdge {
    int target;
    int weight;
};

struct MyNode {
    int identifier;
    vector<MyEdge> links;
};

class MyGraph {
public:
    unordered_map<int, MyNode> vertices;

    void insertEdge(int origin, int target, int weight) {
        vertices[origin].identifier = origin;
        vertices[target].identifier = target;
        vertices[origin].links.push_back({target, weight});
    }

    pair<int, vector<int>> myDijkstra(int start, int end) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> myQueue;
        unordered_map<int, int> distance;
        unordered_map<int, int> previous;

        for (const auto& entry : vertices) {
            int vertex = entry.first;
            distance[vertex] = numeric_limits<int>::max();
            previous[vertex] = -1;
        }

        distance[start] = 0;
        myQueue.push({0, start});

        while (!myQueue.empty()) {
            int current = myQueue.top().second;
            myQueue.pop();

            for (const auto& link : vertices[current].links) {
                int new_distance = distance[current] + link.weight;
                if (new_distance < distance[link.target]) {
                    distance[link.target] = new_distance;
                    previous[link.target] = current;
                    myQueue.push({new_distance, link.target});
                }
            }
        }

        vector<int> myPath;
        int current = end;
        while (current != -1) {
            myPath.push_back(current);
            current = previous[current];
        }

        reverse(myPath.begin(), myPath.end());

        return {distance[end], myPath};
    }

    void displayMyGraph() {
        cout << "digraph MyGraph {" << endl;
        for (const auto& entry : vertices) {
            int origin = entry.first;
            for (const auto& link : vertices[origin].links) {
                int target = link.target;
                int weight = link.weight;
                cout << origin << " -> " << target << " [label=\"" << weight << "\"];" << endl;
            }
        }
        cout << "}" << endl;
    }
};

int main() {
    MyGraph myGraph;

    myGraph.insertEdge(1, 2, 4);
    myGraph.insertEdge(1, 3, 3);
    myGraph.insertEdge(2, 4, 2);
    myGraph.insertEdge(3, 4, 6);
    myGraph.insertEdge(4, 5, 5);

    cout << "Generated DOT representation of MyGraph:" << endl;
    myGraph.displayMyGraph();

    int myStart, myEnd;

    cout << "Enter the starting node: ";
    cin >> myStart;

    cout << "Enter the ending node: ";
    cin >> myEnd;

    auto myResult = myGraph.myDijkstra(myStart, myEnd);

    cout << "Cost of the shortest path: " << myResult.first << endl;
    cout << "Shortest path: ";
    for (int myNode : myResult.second) {
        cout << myNode << " ";
    }

    return 0;
}
