class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pre(n,0);
        if(nums[0] == target) pre[0] = 1;
        for(int i = 1; i < n; i++){
            pre[i] =  (nums[i] == target) ? pre[i-1] + 1 : pre[i-1];
            cout<< pre[i] << " ";
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int tc = pre[j] - (i>0 ? pre[i-1] : 0); 
                if(tc > (j-i+1)/2) cnt++;
            }
        }
        return cnt;
    }
};

// 1 2 2 3
// 1 2 3 4 
// 0 1 2 3 
// i = 1, j = 3