class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        for(int left = 0; left < n; left++){
            set<int> even, odd;
            for(int right = left; right < n; right++){
                if(nums[right] % 2 == 0) even.insert(nums[right]);
                else odd.insert(nums[right]);
                if(even.size() == odd.size()){
                    ans = max(ans, right - left +1);
                }
            }
        }
        return ans;
    }
};