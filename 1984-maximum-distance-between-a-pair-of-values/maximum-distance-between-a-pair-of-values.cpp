class Solution {
public:
    int bs(vector<int>& nums2, int i, int target, int m){
        int low = i;
        int high = m-1;
        int ans = low;
        while(low <= high){
            int mid = low + (high- low) /2;
            if(nums2[mid] >= target){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = -1;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < n; i++){
            int j = bs(nums2, i, nums1[i], m);
            maxi = max(maxi, j-i);
        }
        return maxi;
    }
};