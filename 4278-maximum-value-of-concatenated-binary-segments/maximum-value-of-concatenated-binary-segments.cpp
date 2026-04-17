class Solution {
public:
    int MOD = 1e9+7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> nums;
        int n = nums1.size();
        for(int i = 0; i < n; i++){
            nums.push_back({nums1[i], nums0[i]});
        }
        
        sort(nums.begin(), nums.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            // Arrays to store at most 4 blocks of characters for A+B and B+A
            pair<char, int> r1[4], r2[4];
            int sz1 = 0, sz2 = 0;
            
            // Helper to merge continuous characters into runs
            auto add_run = [](pair<char, int>* r, int& sz, char c, int count) {
                if (count == 0) return;
                if (sz > 0 && r[sz-1].first == c) r[sz-1].second += count;
                else { r[sz] = {c, count}; sz++; }
            };

            // Build runs for Concatenation A + B
            add_run(r1, sz1, '1', a.first);
            add_run(r1, sz1, '0', a.second);
            add_run(r1, sz1, '1', b.first);
            add_run(r1, sz1, '0', b.second);

            // Build runs for Concatenation B + A
            add_run(r2, sz2, '1', b.first);
            add_run(r2, sz2, '0', b.second);
            add_run(r2, sz2, '1', a.first);
            add_run(r2, sz2, '0', a.second);

            // Compare the runs in O(1) time
            int i = 0, j = 0;
            int rem1 = r1[0].second, rem2 = r2[0].second;
            while(i < sz1 && j < sz2) {
                if (r1[i].first != r2[j].first) {
                    return r1[i].first > r2[j].first;
                }
                int mn = min(rem1, rem2);
                rem1 -= mn;
                rem2 -= mn;
                
                if (rem1 == 0) { i++; if (i < sz1) rem1 = r1[i].second; }
                if (rem2 == 0) { j++; if (j < sz2) rem2 = r2[j].second; }
            }
            return false;
        });

        string ans = "";
        for(auto& it : nums){
            // Minor cleanup: append() is much faster than while() push_back
            ans.append(it.first, '1');
            ans.append(it.second, '0');
        }
        
        long long res = 0;
        long long pow = 1;
        for(int j = ans.size()-1; j >= 0; j--){
            if(ans[j] == '1'){
                res = (res + pow) % MOD;
            }
            pow = (pow * 2) % MOD;
        }
        
        return res;
    }
};