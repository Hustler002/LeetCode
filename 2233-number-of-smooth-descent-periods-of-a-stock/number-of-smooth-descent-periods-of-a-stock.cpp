class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        int i = 0;
        int prev = prices[i];
        int size = 1;
        i++;
        while(i < n){
            if(prices[i]+1 == prev){
                size++;
            }
            else{
                
                ans += 1LL*size*(size+1)/2;
                cout<<ans<<endl;
                size = 1;
            }
            prev = prices[i];
            i++;
        }
        ans += 1LL*size*(size+1)/2;
        return ans;
    }
};