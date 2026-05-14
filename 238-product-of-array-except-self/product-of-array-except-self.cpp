class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0), pre(n,0), suf(n,0);
        
        for(int i = 0; i < n; i++){
            pre[i] = i==0 ? nums[i] : nums[i]*pre[i-1];
            suf[n-i-1] = n-i-1==n-1 ? nums[n-i-1] : nums[n-i-1]* suf[n-i];
            //cout<< pre[i] << " "<< suf[i]<<endl;
        }
        ans[0] = suf[1];
        ans[n-1] = pre[n-2];
        for(int i = 1; i < n-1; i++){
            ans[i] = pre[i-1]*suf[i+1];
        }
        return ans;
    }
};