class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0, col = n-1;

        int curr = matrix[0][n-1];
        while(row < m && col >= 0){
            curr = matrix[row][col];
            if(curr == target) return true;
            else if(curr > target){
                col--;
            }
            else row++;
        }
        return false;
    }
};