class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long maxi = 0;
        int n = prices.size();
        vector<pair<int,int>> p;
        for(int i = 0; i< n; i++){
            maxi += 1LL * prices[i] * strategy[i];
            p.push_back({strategy[i],prices[i]});
        }

        // prefix sums: prefPrices and prefSP (strategy * price)
        vector<long long> prefPrices(n+1, 0), prefSP(n+1, 0);
        for(int i = 0; i < n; ++i){
            prefPrices[i+1] = prefPrices[i] + prices[i];
            prefSP[i+1] = prefSP[i] + 1LL * strategy[i] * prices[i];
        }

        long long maxGain = 0;
        int half = k / 2;
        for(int l = 0; l + k <= n; ++l){
            // gain = sum of prices in second half - sum of (strategy*price) over entire k-block
            long long sumPricesSecond = prefPrices[l + k] - prefPrices[l + half];
            long long sumSPsub = prefSP[l + k] - prefSP[l];
            long long gain = sumPricesSecond - sumSPsub;
            if (gain > maxGain) maxGain = gain;
        }

        return maxi + maxGain;
    }
};
