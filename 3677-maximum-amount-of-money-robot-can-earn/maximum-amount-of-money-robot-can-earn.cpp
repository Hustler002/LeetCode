class Solution {
public:
    int m, n;
    


    int solve(vector<vector<int>>& coins, int i, int j, int neu , vector<vector<vector<int>>>& dp){
        if(i == m-1 && j == n-1 ){
            if(coins[i][j] < 0 && neu > 0){
                return 0;
            }
            return coins[i][j];
        }

        if(i >= m || j >= n) return INT_MIN;

        if(dp[i][j][neu] != INT_MIN) return dp[i][j][neu];

        int take = coins[i][j] + max(solve(coins, i+1, j, neu, dp), solve(coins, i, j+1, neu, dp));

        int skip = INT_MIN;
        if(coins[i][j] < 0){
            if(neu > 0){
                skip = max(solve(coins, i+1, j, neu-1, dp), solve(coins, i, j+1, neu-1, dp));
            }
        }

        return dp[i][j][neu] = max(skip,take);
    }


    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (3, INT_MIN)));
        return solve(coins, 0, 0, 2, dp);    

    }
};