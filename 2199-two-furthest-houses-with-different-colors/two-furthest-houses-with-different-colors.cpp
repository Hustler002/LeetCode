class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        for(int i = 0; i < n; i++){
            int j = n-1;
            while(nums[i] == nums[j]){
                j--;
            }
            maxi = max(maxi, abs(j-i));
        }
        return maxi;
    }
};