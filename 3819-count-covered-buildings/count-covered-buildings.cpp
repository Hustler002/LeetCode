class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        
        int cnt = 0;
        map<int,int> minR, maxR, minC, maxC;
        
        for(auto& v : b){
            int r = v[0];
            int c = v[1];
            if(!minR.count(r))  minR[r] = maxR[r] = c;
            else minR[r] = min(minR[r], c), maxR[r] = max(maxR[r], c);

            if (!minC.count(c)) minC[c] = maxC[c] = r;
            else minC[c] = min(minC[c], r), maxC[c] = max(maxC[c], r);
        }

        int N   = b.size();
        for (int i = 0; i < N; ++i) {
            int r = b[i][0];
            int c = b[i][1];
            if (minR[r] < c && c < maxR[r]
                 && minC[c] < r && r < maxC[c]) {
                ++cnt;
            }
        }
        return cnt;
    }
};