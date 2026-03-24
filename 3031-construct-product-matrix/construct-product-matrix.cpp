class Solution {
public:
    int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> pre(n*m, 1), suff(n*m, 1);

        int k = 0;
        pre[k] = grid[0][0] % MOD;
        k++;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(i==0 && j==0) continue;
                
                pre[k] = (1LL * pre[k-1] * grid[i][j]) % MOD; 
                k++;
            }
        }
        
        k = (n*m)-1;
        suff[k] = grid[n-1][m-1] % MOD;
        k--;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i==n-1 && j==m-1) continue;
                suff[k] = (1LL * suff[k+1] * grid[i][j]) % MOD;
                k--; 
            }
        }
        
        vector<int> ans(m*n, 1);
        ans[0] = suff[1];
        ans[(n*m-1)] = pre[(n*m-2)];

        for(int i = 1; i < n*m-1; i++){
            ans[i] = (1LL * pre[i-1] * suff[i+1]) % MOD;
        }

        vector<vector<int>> pro;
        k = 0;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            for(int j = 0; j < m; j++){
                temp.push_back(ans[k]);
                k++;
            }
            pro.push_back(temp);
        }

        return pro;
    }
};