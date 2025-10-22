class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        int max_val = *max_element(nums.begin(),nums.end()) + k;

        unordered_map<int,int> freq;
        map<int,int> diff;

        // cf
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;

            int l = max(0,nums[i]-k);
            int r = min(max_val, nums[i]+k);

            diff[l]++;
            diff[r+1]--;

            diff[nums[i]]+=0;

        }

        int result = 1;
        int cum = 0;

        for(auto it = diff.begin(); it != diff.end(); it++){
            int target = it->first;
            it->second += cum;

            int targetCount = freq[target];

            int need = it->second - targetCount;
            int maxPossFreq = min(need, op);

            result = max(result, targetCount+maxPossFreq);
            cum = it->second;
        }
        return result;
    }
};