class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int med = nums1[0];
        long long ans = 1;
        
        for(int i = 0; i < n; i++){
            int a = nums1[i];
            int b = nums2[i];
            int c = nums2[n];
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(b);
            temp.push_back(c);
            sort(begin(temp),end(temp));
            
            int tmp = temp[1];
            if(abs(tmp-nums2[n]) < abs(med - nums2[n])) med = tmp;
            ans += abs(nums1[i] - nums2[i]);
        }

        
        ans += abs(med - nums2[n]);
        return ans;
    }
};