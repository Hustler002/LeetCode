class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ans[i] = -1;
            } else {
                int x = nums[i];
                int prev = 0;

                for (int i = 0; i <32; i++) {
                    if ((x >> i)&1) {
                        prev = i;
                    } else {
                        break;
                    }
                }

                // x>>prev =0;

                x = x & ~(1 << prev);
                //int y = x++;
                ans[i] = x;
            }
        }
        return ans;
    }
};