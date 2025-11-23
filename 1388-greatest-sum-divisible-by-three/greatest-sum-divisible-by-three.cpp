class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3, INT_MIN));
        //base case
        dp[0][0] = 0;
        //dp
        for(int i=0;i<n;i++){
            int x = nums[i];
            for(int j=0;j<3;j++){
                dp[i+1][j] = max(x + dp[i][(j+x)%3], dp[i][j]);
            }
        }
        return dp[n][0];
    }
};