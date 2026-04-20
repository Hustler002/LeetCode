class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        int i = 0, j = n-1;
        while(nums[i]==nums[j]) j--;
        maxi = max(maxi, abs(i-j));
        j=n-1;
        while(nums[i] == nums[j]) i++;
        maxi = max(maxi, abs(i-j));
        return maxi;
    }
};