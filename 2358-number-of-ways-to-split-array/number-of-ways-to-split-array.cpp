class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        long long  total = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = 0;

        for(int i = 0; i < n-1; i++){
            long long first = prefix[i];
            long long second = total - first;
            if(first >= second) ans++;
        }
        return ans;
    }
};