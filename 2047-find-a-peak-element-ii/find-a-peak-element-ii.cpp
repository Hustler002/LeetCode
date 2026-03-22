class Solution {
public:
    pair<int,int> findMax(vector<vector<int>>& mat , int mid, int n, int m){
        pair<int,int> index = {-1,-1};
        int maxi = -1;
        for(int i = 0; i < m; i++){
            if(mat[i][mid] > maxi){
                maxi = mat[i][mid];
                index = {i,mid};
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            pair<int,int> maxi = findMax(mat, mid, n, m);
            int i = maxi.first;
            cout<<mat[i][mid];
            if((mid-1 >=0 ? mat[i][mid-1] < mat[i][mid]: 1) && (mid+1 < n ? mat[i][mid+1] < mat[i][mid] : 1))
                return {i,mid};
            else if((mid-1 >=0 ? mat[i][mid-1] < mat[i][mid]: 1))
                low = mid+1;
            else if(mid+1 < n ? mat[i][mid+1] < mat[i][mid] : 1) 
                high = mid-1;
        }
        return {-1,-1};
    }
};