#include<vector>
using namespace std;

class Solution {
public:
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n); // adjacency list representation of the graph
    vector<int> dfs_num(n), low(n); // discovery time and low discovery time of each vertex
    vector<vector<int>> critical; // list of critical connections
    int time = 0; // current discovery time
    
    // build the graph
    for (auto& c : connections) {
        int u = c[0], v = c[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // DFS function to find critical connections
    function<void(int, int)> dfs = [&](int u, int parent) {
        dfs_num[u] = low[u] = ++time;
        for (int v : graph[u]) {
            if (!dfs_num[v]) { // v has not been visited yet
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfs_num[u]) {
                    critical.push_back({u, v});
                }
            } else if (v != parent) {
                low[u] = min(low[u], dfs_num[v]);
            }
        }
    };
    
    // perform DFS starting from vertex 0
    dfs(0, -1);
    return critical;
}

};