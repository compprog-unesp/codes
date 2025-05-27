#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> temperatures;
vector<bool> visited;
int n, k, max_path = 0;

int dfs(int node, int depth) {
    if (visited[node])
        return 0;

    visited[node] = true;

    int total_nodes = 0;

    for (int neighbor : graph[node])
        total_nodes += dfs(neighbor, depth+1);

    if (total_nodes) {
        max_path = max(max_path, depth);
        return total_nodes + 1;
    }
    
    if (temperatures[node] > k) {
        max_path = max(max_path, depth);
        return 1;
    }
    
    return 0;
}


int main() {
    cin >> n >> k;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        temperatures.push_back(x);
    }

    visited.assign(n, false);
    graph.assign(n, vector<int>());

    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    int total = dfs(0, 0);
    if (total == 2)
        cout << 1;
    else if (total > 1)
        cout << (total-1)*2 - max_path;
    else
        cout << 0;

    return 0;
}