class Solution {
public:
    int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto& it : queries){
            int idx = it[0];
            while(idx <= it[1]){
                long long res = (nums[idx]);
                nums[idx] =  (res*it[3]) % MOD;
                idx += it[2];
            }
        }
        int ans = 0;
        for(auto& it : nums) ans = ans^it;
        return ans;
    }
};