class Solution {
public:
    long long maximumTotalSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());

        long long sum = nums[0];

        for(int i = 1; i < n; i++){
            nums[i] = min(nums[i], nums[i-1]-1);
            if(nums[i] == 0) return -1;
            sum += nums[i];
        }
        return sum;
    }
};