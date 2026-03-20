class Solution {
public:
int minDiffSet(const set<int>& s) {
    if (s.size() < 2) return 0;

    int minDiff = INT_MAX;
    auto it = s.begin();
    auto prev = it++;

    while (it != s.end()) {
        minDiff = min(minDiff, abs(*it - *prev));
        prev = it++;
    }
    return minDiff;
}
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));

        for(int i = 0; i < m-k+1; i++){
            for(int j = 0; j < n-k+1; j++){
                set<int> s;
                for(int l = 0; l < k; l++){
                    for(int z = 0; z < k; z++){
                        s.insert(grid[i+l][j+z]);
                    }
                }
                ans[i][j] = minDiffSet(s);
            }
        }
        return ans;
    }
};