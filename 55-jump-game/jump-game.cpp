class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, th = 0;
        for(int i = n-2; i >= 0; i--){
            if(nums[i]==0){
                cnt++;
            }
            else if(cnt != 0){
                th++;
                if(nums[i] >= th+cnt){
                    cnt =0;
                    th = 0;
                }
            }
        }
        return cnt == 0;
    }
};