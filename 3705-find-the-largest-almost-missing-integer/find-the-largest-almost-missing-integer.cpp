class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();

        int num1 = nums[0], num2 = nums[n-1];
        if(k==1){
            unordered_map<int,int> mpp;

            for(auto& it : nums){
                mpp[it]++;
            }
            int maxi = -1;
            for(auto& it : mpp){
                if(it.second== 1) maxi = max(maxi, it.first);
            }
            return maxi;
        }
        if(k == n) return *max_element(nums.begin(),nums.end());

        int cnt1 =0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == num1) cnt1++;
            if(nums[i] == num2) cnt2++;
        }
        if(cnt1 > 1 && cnt2 > 1) return -1;
        else if(cnt1 > 1) nums[0] = -1;
        else if(cnt2 > 1) nums[n-1] = -1;

        return max(nums[0], nums[n-1]);
    }
};