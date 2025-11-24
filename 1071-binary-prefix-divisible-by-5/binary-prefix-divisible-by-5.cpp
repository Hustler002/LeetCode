class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans(n);
        int r = 0; 
        
        for (int i = 0; i < n; i++) {
            r = ((r << 1) + nums[i]) % 5;
            ans[i] = (r == 0);
        }
        return ans;
    }
};
