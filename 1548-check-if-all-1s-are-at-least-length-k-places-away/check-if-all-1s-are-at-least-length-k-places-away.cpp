class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = 0;
        while(prev < nums.size() && nums[prev] != 1) prev++;
        
        for(int curr = prev+1; curr < nums.size(); curr++){
            if(nums[curr] == 1){
                if(curr - prev-1 < k){
                    return false;
                }
                prev = curr;
            }
        }
        return true;
    }
};