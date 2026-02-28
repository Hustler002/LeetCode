
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int cnt = 0;
        int j = 0;
        int i;
        for(i = 0; i < n-1; i++){
            if(nums[i] != nums[i+1]){
                cnt++;
                nums[j] = nums[i];
                j++;
            }
        }
        cnt++;
        
        nums[j] = nums[i];
        return cnt;
    }
};