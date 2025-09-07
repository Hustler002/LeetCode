class Solution {
public:
    int minOperations(vector<int>& nums) {
        int num = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] != num) return 1;
        }
        return 0;
    }
};