class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || numRows >= s.size()) return s;
        int col = 0;
        int n = s.size();
        int m = numRows-2;
        int i=0;
        while(n > 0) {
            if(i%2 == 0){
                if(n < numRows){
                    col++;
                    break;
                }
                col++;
                n -= numRows;
            }
            else{
                if(n < m){
                    col+= n;
                    break;
                }
                col += m;
                n = n-m;
            }
            i++;
        }
        n = s.size();
        //cout<<col<<endl;
        vector<vector<char>> grid(numRows,vector<char>(col,' '));
        int k = 0;
        i=0;
        //for(int i = 0; i < col; i++){
        while(i < col && k < n){
            if(i%(m+1) == 0){
                for(int j = 0; j < numRows && k < n; j++){
                    grid[j][i] = s[k++];
                }
                i++;
            }
            else{
                int row = m;
                
                while(row>0 && k < n){
                    grid[row][i] = s[k++];
                    i++;
                    row--;
                }
            }
        }
        string res = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] != ' ') res.push_back(grid[i][j]);
            }
        }
        return res;
    }
};