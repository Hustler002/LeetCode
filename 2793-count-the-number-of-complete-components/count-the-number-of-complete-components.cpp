class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;

        // DFS to find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                // Check if the component is complete
                int size = component.size();
                int edgeCount = 0;

                for (int node : component) {
                    edgeCount += adj[node].size();
                }

                if (edgeCount / 2 == (size * (size - 1)) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};
