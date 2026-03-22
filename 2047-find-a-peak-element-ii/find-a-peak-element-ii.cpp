class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i-1 >= 0 ? mat[i][j] > mat[i-1][j] : 1) && (i+1 < m ? mat[i][j] > mat[i+1][j] : 1) && (j-1 >= 0 ? mat[i][j] > mat[i][j-1]: 1) && (j+1 < n ? mat[i][j] > mat[i][j+1] : 1)) return {i,j};
            }
        }
       return {-1,-1};
    }
};