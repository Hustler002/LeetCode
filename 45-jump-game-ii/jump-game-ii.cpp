class Solution {
public:
    // int fun(vector<int>& dp, int i, vector<int>& nums){
    //     int n = nums.size();
    //     if(i>=n-1) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     int mini = 1e8;
    //     for(int j = i+1; j<= nums[i] + i; j++){
    //         mini = min (mini, 1 + fun(dp, j, nums));
    //     }

    //     return dp[i] = mini;
    // }
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,0);
        dp[n-1] = 0;

        for(int i = n-2; i >= 0 ; i--){
            int mini = 1e8;
            for(int j = i+1; j<= nums[i] + i; j++){
                if( j < n) mini = min (mini, 1 + dp[j]);
            }
            dp[i] = mini;
        }

        return dp[0];
    }
};