class Solution {
public:
# define ll long long
    ll maximumProfit(vector<int>& P, int K) {
        int n = P.size();
        const ll NEG_INF = LLONG_MIN / 4;
        
        vector<vector<array<ll,3>>> dp(K+1, vector<array<ll,3>>(n));
        
        for(int j = 0; j < n; j++){
            dp[0][j][0] = 0;
            dp[0][j][1] = NEG_INF;
            dp[0][j][2] = NEG_INF;
        }
        
        for(int t = 1; t <= K; t++){
            dp[t][0][0] = 0;
            dp[t][0][1] = -P[0];
            dp[t][0][2] =  P[0];
            for(int j = 1; j < n; j++){
                dp[t][j][0] = max({
                    dp[t][j-1][0],
                    dp[t][j-1][1] + P[j],
                    dp[t][j-1][2] - P[j]
                });
                dp[t][j][1] = max(
                    dp[t][j-1][1],
                    dp[t-1][j-1][0] - P[j]
                );
                dp[t][j][2] = max(
                    dp[t][j-1][2],
                    dp[t-1][j-1][0] + P[j]
                );
            }
        }
        
        return dp[K][n-1][0];
    }
};
