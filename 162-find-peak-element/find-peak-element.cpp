class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(n==2){
            if(nums[0] < nums[1]) return 1;
            else return 0;
        }

        int low = 1, high = n-2;

        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1] > nums[mid]) high = mid-1;
            else if(nums[mid] < nums[mid+1]) low = mid+1;
        }
        if(nums[0] > nums[1]) return 0;
        return n-1;
    }
};