class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int max_val = *max_element(nums.begin(),nums.end()) + k;

        vector<int> freq(max_val+1,0);

        for(int &num : nums){
            freq[num]++;
        }

        // cf
        for(int i = 1; i <= max_val; i++){
            freq[i] += freq[i-1];
        }

        int result = 0;
        for(int target = 0; target <= max_val; target++){
            if(freq[target] == 0) continue;

            int leftNum = max(0,target - k);
            int rightNum = min(max_val, target + k);

            int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum-1] : 0);

            int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);

            int need = totalCount - targetCount;
            int maxPossFreq = targetCount + min(need, numOperations);

            result = max(result, maxPossFreq);
        }
        return result;
    }
};