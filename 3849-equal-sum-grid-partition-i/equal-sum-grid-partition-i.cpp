class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> rows(m,0);

        for(int i = 0; i < m; i++){
            long long sum = 0;
            for(int j = 0; j < n; j++){
                sum += grid[i][j];
            }
            rows[i] = sum;
        }

        vector<long long> cols(n,0);

        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = 0; j < m; j++){
                sum += grid[j][i];
            }
            cols[i] = sum;
        }

        bool valid = false;

        long long total = accumulate(rows.begin(), rows.end(),0LL);
        long long sum = 0;
        for(int i = 0; i < m; i++){
            sum+= rows[i];
            if(sum*2 == total) return true;
        }

        sum = 0;
        for(auto& it : cols){
            sum += it;
            if(sum*2 == total) return true;
        }
        return false;
    }
};