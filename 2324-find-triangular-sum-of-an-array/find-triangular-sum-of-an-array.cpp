class Solution {
public:
    int solve(vector<int> nums, int n){
        if(n == 1) return nums[0];

        vector<int> curr(n-1,0);
        for(int i = 0; i < n-1; i++){
            curr[i] = (nums[i] + nums[i+1])%10;
        }
        return solve(curr,n-1);
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        return solve(nums,n);
        
    }
};