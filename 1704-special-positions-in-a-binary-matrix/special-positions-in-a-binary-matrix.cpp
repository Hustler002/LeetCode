class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> rows(n,0);
        for(int i = 0; i< n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    sum++;
                }
            }
            rows[i] = sum;
        }
        vector<int> cols(m,0);
        for(int i = 0; i< m; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(mat[j][i] == 1){
                    sum++;
                }
            }
            cols[i] = sum;
        }
        int cnt = 0;
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1){
                    if(rows[i] == 1 && cols[j] == 1) cnt++;
                }
            }
        }
        return cnt;
    }
};