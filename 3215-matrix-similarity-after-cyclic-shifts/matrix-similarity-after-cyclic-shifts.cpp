class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();
        k=k%n;
        vector<vector<int>> mod(m,vector<int>(n,1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i%2==0){
                    int idx = (((j-k) + n) % n)%n;
                    mod[i][idx] = mat[i][j];
                }
                else{
                    int idx = ((j+k) % n)%n;
                    mod[i][idx] = mat[i][j];
                }
            }
        }
        return(mod==mat);
    }
};