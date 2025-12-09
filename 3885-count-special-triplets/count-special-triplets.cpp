class Solution {
public:
    const int MOD = 1e9+7;
    #define ll long long
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        ll cnt = 0;
        //num -> ind,freq
        unordered_map<ll,ll> left, right;
        for(int x:nums) right[x]++;
        for(int j = 0; j < n; j++){
            right[nums[j]]--;
            ll t = nums[j] * 2LL;
            if(left.count(t) && right.count(t))
                cnt = (cnt+left[t]*right[t]) % MOD;
            left[nums[j]]++;
        }
        return cnt;
    }
};