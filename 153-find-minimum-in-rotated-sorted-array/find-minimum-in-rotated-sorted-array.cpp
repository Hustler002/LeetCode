class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] >= nums[0] && nums[mid] <= nums[n-1]) return nums[0];
            else if(nums[mid] < nums[0]){
                ans = nums[mid];
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};