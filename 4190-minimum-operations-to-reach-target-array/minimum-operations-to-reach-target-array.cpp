class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int op = 0;
        unordered_map<int,int> mpp;
        for(auto& it : nums) mpp[it]++;

        set<int> vis;

        for(int i = 0; i < nums.size(); i++){
            if(vis.find(nums[i]) != vis.end()){
                continue;
            }
            if(nums[i] != target[i]) {
                op++;
                vis.insert(nums[i]);
            }
        }
        return op;
    }
};