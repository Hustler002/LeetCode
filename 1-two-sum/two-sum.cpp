class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]] = i;
        }
        for(int i = 0; i < n; i++){
            if(mpp.find(target-nums[i]) != mpp.end() && mpp[target- nums[i]] != i){
                return {i,mpp[target-nums[i]]};
            }
        }
        return {-1,-1};
    }
};