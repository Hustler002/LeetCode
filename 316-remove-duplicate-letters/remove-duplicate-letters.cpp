class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        string ans = "";

        stack<char> st;
        unordered_map<char,int> mpp;

        for(auto& it : s){
            mpp[it]++;
        }
        vector<bool> vis(26,false);
        for(auto& it : s){
            mpp[it]--;

            if(vis[it - 'a']) continue;
            while(!st.empty()){
                char tp = st.top();
                if(tp >= it && mpp[tp] >= 1) {
                    st.pop();
                    vis[tp-'a'] = false;
                }
                else break;
            }
            st.push(it);
            vis[it-'a'] = true;
        }
        
        while(!st.empty()){
            char it = st.top();
            st.pop();
            ans.push_back(it);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};