class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i = x;
        int l = x+k-1;
        while(l>i){
            for(int j = y; j < y+k; j++){
                //swap(grid[i][j], grid[x+k-i][j]);
                int temp = grid[i][j];
                grid[i][j] = grid[l][j];
                grid[l][j] = temp;
            }
            i++;
            l--;
        }

        return grid;
    }
};