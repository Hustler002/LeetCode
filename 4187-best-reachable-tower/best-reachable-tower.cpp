class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int maxi = -1;
        vector<int> ans = {-1,-1};
        for(auto& it : towers){
            int x = it[0];
            int y = it[1];
            int d = abs(x-center[0]) + abs(y-center[1]);
            if(d > radius) continue;
            if(it[2] > maxi) {
                maxi = it[2];
                ans = {x,y};
            }
            if(it[2] == maxi){
                if (ans[0] == -1 || x < ans[0] || (x == ans[0] && y < ans[1])) {
                    ans = {x, y};
                }
            }
        }
        return ans;
    }
};