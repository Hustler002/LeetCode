class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        bool flag1 = false, flag2 = false, flag3 = false;
        while(i+1 < n && nums[i+1]>nums[i]){
            i++;
            flag1 = true;
        }
        while(i+1 < n && nums[i+1]<nums[i]){
            i++;
            flag2 = true;
        }
        while(i+1 < n && nums[i+1]>nums[i]){
            i++;
            flag3 = true;
        }
        if(i+1<n) return false;
        if(flag1 && flag2 && flag3) return true;
        return false;
    }
};