class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int limit = n/3;

        vector<int> ans;
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 = 1;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){
                cnt2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }

        }
        cnt1 = 0, cnt2 = 0;
        for(auto& it : nums){
            if(it==el1) cnt1++;
            if(it == el2) cnt2++;
        }
        if(cnt1 > limit) ans.push_back(el1);
        if(cnt2 > limit) ans.push_back(el2);
        return ans;
    }
};