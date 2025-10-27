class Solution {
public:
    int n, m;
    int mod = 1e9+7;
    int solve(int i, int gcdd, vector<vector<int>>& mat, vector<vector<int>> &dp) {

        if (i == n) {
            if (gcdd == 1)
                return 1;
            return 0;
        }
        if(dp[i][gcdd]!=-1) return dp[i][gcdd];

        int cnt = 0;
        for (int k = 0; k < m; k++) {

            cnt = (cnt%mod+ solve(i + 1, __gcd(gcdd, mat[i][k]), mat,dp)%mod)%mod;
        }

        return dp[i][gcdd]= cnt%mod;
    }

    int countCoprime(vector<vector<int>>& mat) {

        n = mat.size();
        m = mat[0].size();
        long long  cnt = 0;
        int i = 0;
        vector<vector<int>> dp(n+1,vector<int>(151,-1));
        
        for (int j = 0; j < m; j++) {
            cnt= cnt+ (solve(1, mat[0][j], mat,dp))%mod;
            
        }
        return cnt%mod;
    }
};