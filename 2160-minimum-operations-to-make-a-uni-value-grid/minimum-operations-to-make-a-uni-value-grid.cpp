class Solution {
public:
    vector<int> list;

    bool Possible(vector<vector<int>>& grid, int x){
        
        int rem = grid[0][0] % x;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                list.push_back(grid[i][j]);
                if((grid[i][j] % x) != rem){
                    return false;
                }
            }
        }
        return true;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        if(!Possible(grid, x)){
            return -1;
        }
        int op = 0;
        sort(list.begin(),list.end());
        int n = list.size();
        int target = list[n/2];    
        for(int i = 0; i < n; i++){
            op += abs(target - list[i]) / x;
        }
        return op;
    }
};