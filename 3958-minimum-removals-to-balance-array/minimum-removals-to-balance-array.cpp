class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int i = 0, mx = 0;
        
        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k)
                i++;
            
            mx = max(mx, j - i + 1);
        }
        
        return n - mx;
    }
};
