class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int cnt = 0;
        int j = 0;
        int i=0;
        int prev=0;
        int cprev=0;
        if(n==2 && nums[0]!=nums[1])
        {
            return 2;
        }
        // if(n==2 && nums[0]==nums[1])
        // {
        //     return 1;
        // }
        
        for(i = 0; i < n-1; i++){
            if(nums[i] != nums[i+1]){
                cprev=nums[i];
                prev=nums[i+1];
                cnt++;
                nums[j] = nums[i];
                j++;
            }
        }
        if(cprev!=prev)
        {
            nums[j]=prev;
            cnt++;
        }
        if(n>0 && cnt==0)
         {
            return 1;
         }
        return cnt;
    }
};