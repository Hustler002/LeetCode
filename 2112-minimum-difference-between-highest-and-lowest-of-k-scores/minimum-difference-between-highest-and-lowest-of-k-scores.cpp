class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mini = INT_MAX;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i < n-k+1; i++){
            int diff = nums[i+k-1]-nums[i];
            mini = min(diff,mini);
        }
        return mini;
    }
};