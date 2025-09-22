class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto& it : nums) mpp[it]++;

        int cnt = 0;
        int maxi = INT_MIN;
        for(auto& it : mpp){
            maxi = max(maxi,it.second);
        }
        for(auto& it : mpp){
            if(it.second == maxi){
                cnt += it.second;
            }
        }
        return cnt;

    }
};