#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set Union for cycle detection and component connection
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) parent[root_i] = root_j;
            else if (rank[root_i] > rank[root_j]) parent[root_j] = root_i;
            else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
            return true; // Successfully connected
        }
        return false; // Cycle detected
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> must_edges, opt_edges;
        int min_must = 2e9, must_count = 0;
        DSU dsu_init(n);
        
        // Step 1: Base mandatory checks
        for(auto& e : edges) {
            if(e[3] == 1) {
                must_edges.push_back(e);
                min_must = min(min_must, e[2]);
                if(!dsu_init.unite(e[0], e[1])) return -1; // Cycle in mandatory edges
                must_count++;
            } else {
                opt_edges.push_back(e);
            }
        }
        
        int low = 1, high = 2e5, ans = -1;
        
        // Step 3: Validation function
        auto check = [&](int mid) {
            if (must_count > 0 && min_must < mid) return false;
            
            DSU dsu(n);
            int edges_used = 0, upgrades = 0;
            
            for(auto& e : must_edges) {
                dsu.unite(e[0], e[1]);
                edges_used++;
            }
            
            vector<vector<int>> cost0, cost1;
            for(auto& e : opt_edges) {
                if (e[2] >= mid) cost0.push_back(e);
                else if (e[2] * 2 >= mid) cost1.push_back(e);
            }
            
            // Greedily use 0-upgrade edges first
            for(auto& e : cost0) {
                if(dsu.unite(e[0], e[1])) edges_used++;
            }
            
            // Use 1-upgrade edges if needed
            for(auto& e : cost1) {
                if(dsu.unite(e[0], e[1])) {
                    edges_used++;
                    upgrades++;
                }
            }
            
            return (edges_used == n - 1) && (upgrades <= k);
        };
        
        // Step 2: Binary Search implementation
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(check(mid)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};