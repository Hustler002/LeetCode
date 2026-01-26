class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            int diff = nums[i+1]- nums[i];
            mini = min(mini,diff);
        }
        for(int i = 0; i < n-1; i++){
            int diff = nums[i+1]- nums[i];
            if(diff == mini){
                ans.push_back({nums[i],nums[i+1]});
            }
        }
        return ans;
    }
};