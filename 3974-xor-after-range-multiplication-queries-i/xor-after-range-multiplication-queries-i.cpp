class Solution {
public:
    const int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            long long v = it[3];
            int idx = l;
            while(idx <= r){
                long long num = nums[idx];
                nums[idx] = (num*v)%MOD;
                idx += k;
            }
        }
        int res = nums[0];
        for(int i = 1; i < n; i++){
            res ^= nums[i];
        }
        return res;
    }
};