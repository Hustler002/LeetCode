class Solution {
public:
    bool fun(vector<int>& nums, int curr, vector<int>& vis){
        if(nums[curr] == 0) return true;
        if(vis[curr]) return false;
        vis[curr] = true;
        bool left = false, right = false;
        if(curr - nums[curr] >= 0)
            left = fun(nums, curr - nums[curr], vis);
        if(curr + nums[curr] < nums.size())
            right = fun(nums, curr + nums[curr], vis);
        return (left || right);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,false);
        return fun(arr, start, vis);
    }
};