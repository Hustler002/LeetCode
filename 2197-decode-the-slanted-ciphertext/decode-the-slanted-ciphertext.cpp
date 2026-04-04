class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int n = s.size();
        int cols = n / rows;
        vector<vector<char>> grid(rows, vector<char> (cols, ' '));
        int k = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j  < cols; j++){
                grid[i][j] = s[k];
                k++;
            }
        }

        string res = "";
        int p=0,q=0;
        int i = 0, j = 0;
        while(j < cols){
            res.push_back(grid[i][j]);
            i++;
            j++;
            if(i >= rows || j >= cols){
                i = 0;
                q++;
                j = q;
            }
        }
        while(!res.empty() && res.back() == ' ') {
            res.pop_back();
        }
        return res;

    }
};

// ch...ie... p  r
// 0123456789 10 11