class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total+= grid[i][j];
            }
        }

        // Horizontal cut
        unordered_set<long long> st;
        long long top = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                top += grid[i][j];
                st.insert(grid[i][j]);
                
            }
            long long bottom = total - top;

            long long diff = top - bottom;
            if(diff == 0) return true;
            if(st.find(diff) != st.end())   {
                if((i==0 || n ==1) && (diff != grid[0][0] && diff != (i==0 ? grid[0][n-1] : grid[i][0]))) continue;
                return true;
            }
        }


        st.clear();
        top = 0;
        for(int i = m-1; i >=0; i--){
            for(int j = 0; j < n; j++){
                top += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long bottom = total - top;

            long long diff = top - bottom;
            if(diff == 0) return true;
            if(st.find(diff) != st.end())   {
                if((i==m-1 || n==1) && (diff != grid[m-1][0] && diff != (i == m-1 ? grid[m-1][n-1] : grid[i][0]))) continue;
                return true;
            }
        }
        // Vertical Cut

        st.clear();
        top = 0;
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                top += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long bottom = total - top;

            long long diff = top - bottom;
            if(diff == 0) return true;
            if(st.find(diff) != st.end())   {
                if((j==0 || m == 1)&& (diff != grid[0][0] && diff != (j==0 ? grid[m-1][0]: grid[0][j]))) continue;
                return true;
            }
        }

        st.clear();
        top = 0;
        for(int j = n-1; j >= 0; j--){
            for(int i = 0; i < m; i++){
                top += grid[i][j];
                st.insert(grid[i][j]);
            }
            long long bottom = total - top;

            long long diff = top - bottom;
            if(diff == 0) return true;
            if(st.find(diff) != st.end())   {
                if((j==n-1 || m==1) && (diff != grid[0][n-1] && diff != (j==n-1 ? grid[m-1][n-1]: grid[0][j]))) continue;
                return true;
            }
        }

        return false;
    }
};