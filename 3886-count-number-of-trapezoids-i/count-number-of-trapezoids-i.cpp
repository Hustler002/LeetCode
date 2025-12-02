class Solution {
public:
    #define ll long long
    static constexpr int MOD = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,int> mpp;
        mpp.reserve(n);
        for(auto& p :points){
            int x = p[0];
            int y = p[1];
            mpp[y]++;
        }
        ll cnt =0, prefix = 0;
        
        for(auto it = mpp.begin(); it!= mpp.end(); ++it){
            
            int n1 = it->second;
            if(n1 < 2) continue;
            
            ll c1 = (1LL * n1 * (n1 - 1) / 2) % MOD;
            
            cnt = (cnt + prefix*c1 % MOD) % MOD;
            prefix = (prefix+c1) % MOD;
        }
        return (int)cnt;
    }
};