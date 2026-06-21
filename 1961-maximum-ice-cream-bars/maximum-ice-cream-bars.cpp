class Solution {
public:
    void counting_sort(vector<int>& nums){
        int maxi = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxi+1,0);

        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        int idx = 0;
        for(int i = 0; i < freq.size(); i++){
            while(freq[i]--) {
                nums[idx] = i;
                idx++;
            }
        }
    }
    int maxIceCream(vector<int>& costs, int coins) {
        
        counting_sort(costs);
        int i = 0;
        int cnt = 0;
        while(i < costs.size() && coins >= costs[i]){
            coins -= costs[i];
            cnt++;
            i++;
        }
        return cnt;
    }
};