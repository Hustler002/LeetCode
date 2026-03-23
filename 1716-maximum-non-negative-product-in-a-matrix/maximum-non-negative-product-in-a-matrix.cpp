class Solution {
public:
    int MOD = 1e9+7;
    #define ll long long
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<ll,ll>>> dp(m,vector<pair<ll,ll>>(n,{1,1}));
        dp[0][0] = {grid[0][0], grid[0][0]};
        for(int i = 1; i < n; i++){
            dp[0][i] = {dp[0][i-1].first*grid[0][i], dp[0][i-1].first*grid[0][i]};
        }

        for(int i = 1; i < m; i++){
            dp[i][0] = {dp[i-1][0].first* grid[i][0], dp[i-1][0].first* grid[i][0]};
        }


        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                ll max_val = max(dp[i-1][j].first, dp[i][j-1].first);
                ll min_val = min(dp[i-1][j].second, dp[i][j-1].second);
                dp[i][j].first = max(grid[i][j] * max_val, grid[i][j]* min_val);

                dp[i][j].second = min(grid[i][j] *max_val,  grid[i][j]* min_val);
            }
        }
        ll ans = max(dp[m-1][n-1].first, dp[m-1][n-1].second);
        ans = ans % MOD;
        return ans < 0 ? -1 : ans; 
    }
};