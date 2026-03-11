class Solution {
public:
    int findDays(vector<int> weights, int cap){
        int d = 1;
        int temp = cap;
        for(auto& it : weights){
            if(it <= temp) temp = temp - it;
            else{
                temp = cap;
                d++;
                temp = temp - it;
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = INT_MAX;

        int ans = high;

        while(low <= high){
            int mid = low + (high-low) / 2;

            int D = findDays(weights, mid);
            if(D <= days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};