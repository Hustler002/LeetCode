class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m, 1));
        long long MOD = 12345;
        
        // Pass 1: Compute and store prefix products directly into 'p'
        long long prefix = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = prefix; // Store the product of all elements before (i, j)
                prefix = (prefix * grid[i][j]) % MOD; // Update running prefix
            }
        }
        
        // Pass 2: Compute suffix products on the fly and multiply with 'p'
        long long suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (p[i][j] * suffix) % MOD; // Multiply prefix by suffix
                suffix = (suffix * grid[i][j]) % MOD; // Update running suffix
            }
        }
        
        return p;
    }
};