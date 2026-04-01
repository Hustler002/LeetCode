class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> ans;

        stack<pair<int,int>> st;
        int n = ast.size();

        for(int i = 0; i < n; i++){
            if(ast[i] > 0){
                st.push({ast[i],i});
            }
            else{
                while(!st.empty() && st.top().first < abs(ast[i])){
                    ast[st.top().second] = 0;
                    st.pop();
                }
                if (!st.empty() && st.top().first == abs(ast[i])){
                    ast[st.top().second] = 0;
                    st.pop();
                    ast[i] = 0;
                    
                }
                else if(!st.empty() && st.top().first > abs(ast[i])){
                    ast[i] = 0;
                }
                
            }
        }
        for(auto& it : ast)
            if(it != 0) 
                ans.push_back(it);

        return ans;
    }
};