class Solution {
public:
    #define ll long long
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        vector<pair<int,int>> vals(n);
        set<int> vis;
        for(int i = 0; i < n; i++){
            vals.push_back({nums[i],i});
        }
        ll ans = 0;
        sort(vals.begin(),vals.end(),greater<pair<int,int>>());

        for(auto& it : vals){
            int val =it.first;
            int i = it.second;
            auto itt = vis.lower_bound(i);
            if(itt != vis.end()){
                int r = *itt;
                if(r-i >= 2) ans += 1;
            }
            if(itt != vis.begin()){
                auto it1 = itt;
                --it1;
                int l = *it1;
                if(i-l >= 2) ans += 1;
            }
            vis.insert(i);
        }
        return ans;
    }
};