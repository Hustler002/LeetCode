class Solution {
public:
    bool check(int curr, int dir, vector<int> nums){
        int sum = accumulate(nums.begin(),nums.end(),0);
        //6
        while(curr >=0 && curr <= nums.size()-1){
            if(nums[curr] == 0) curr += dir;
            else if(nums[curr] > 0) {
                nums[curr]--;
                dir*=-1;
                curr += dir;
                sum--;
            }
        }
        if(sum==0) return true;
        return false;
        
    }
    int countValidSelections(vector<int>& nums) {
        int cnt = 0;
        for(int i =0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(check(i,-1, nums)) cnt++;
                if(check(i,+1, nums)) cnt++;
            }
        }
        return cnt;
    }
};