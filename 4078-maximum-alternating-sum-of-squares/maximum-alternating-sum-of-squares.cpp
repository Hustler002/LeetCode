class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> numss;
        for(auto&it: nums){
            if(it<0) numss.push_back(it*-1);
            else numss.push_back(it);
        }

        sort(numss.begin(),numss.end());
        int n = numss.size();
        long long sum1 = 0;
        for(int i = 0; i < n/2; i++){
            sum1 += numss[i]*numss[i]*1LL;
        }
        long long sum2 = 0;
        for(int i = n/2; i < n; i++){
            sum2 += numss[i]*numss[i]*1LL;
        }

        return sum2-sum1;
        
    }
};