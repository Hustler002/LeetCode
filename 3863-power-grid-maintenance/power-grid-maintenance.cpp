class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& conn, vector<vector<int>>& q) {
        
        vector<vector<int>> adj(c+1);
        for(auto &it : conn){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(c+1);
        iota(parent.begin(), parent.end(),0);
        function<int(int)> findp = [&](int x){
            return parent[x] == x ? x : parent[x] = findp(parent[x]);
        };
        auto unite = [&](int a, int b){
            a = findp(a); b = findp(b);
            if(a!= b) parent[b] = a;
        };
        for(auto &it : conn){
            unite(it[0],it[1]);
        }

        vector<set<int>> compSet(c+1);
        for (int i = 1; i <= c; ++i) {
            compSet[findp(i)].insert(i);
        }
        
        int k = q.size();
        vector<bool> active(c+1, true);
        vector<int> ans;
        for(int i = 0; i < k; i++){
            if(q[i][0] == 2){
                active[q[i][1]] = false;
                compSet[findp(q[i][1])].erase(q[i][1]);
            }
            else{
                if(active[q[i][1]] == true) ans.push_back(q[i][1]);
                else{
                    auto &st = compSet[findp(q[i][1])];
                    ans.push_back(st.empty() ? -1 : *st.begin());
                }
            }
        }
        return ans;
    }
};