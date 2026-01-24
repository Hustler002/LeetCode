class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxi = -1;
        int i = 0;
        int j = n-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            maxi = max(maxi, sum);
            i++;
            j--;
        }
        return maxi;
    }
};