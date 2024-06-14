#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to initialize a graph
unordered_map<string, vector<pair<string, double>>> initializeGraph(vector<vector<string>>& equations, vector<double>& values) {
    unordered_map<string, vector<pair<string, double>>> graph;

    // Iterate through the equations and values
    for (int i = 0; i < equations.size(); i++) {
        string from = equations[i][0];
        string to = equations[i][1];
        double value = values[i];

        // Add the edge from 'from' to 'to' with the given value
        graph[from].push_back({to, value});

        // Add the reverse edge from 'to' to 'from' with the reciprocal value
        graph[to].push_back({from, 1.0 / value});
    }

    return graph;
}




int main() {
    // Example usage
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"c", "d"}};
    vector<double> values = {2.0, 3.0, 4.0};

    unordered_map<string, vector<pair<string, double>>> graph = initializeGraph(equations, values);

    // Print the graph
    for (const auto& entry : graph) {
        cout << entry.first << ": ";
        for (const auto& neighbor : entry.second) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }

    vector<string> nodesidx ;
    for(auto i : graph){
        nodesidx.push_back(i.first);
    }
    vector<vector<double>> dist(nodesidx.size(), vector<double>(nodesidx.size(), -1));
    

    return 0;
}