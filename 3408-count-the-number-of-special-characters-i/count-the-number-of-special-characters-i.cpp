class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        unordered_set<char> st;
        for(auto& c : word){
            st.insert(c);
        }

        for(auto& it : st){
            if(it >= 'a' && it <= 'z'){
                
                if(st.find(toupper(it)) != st.end()) cnt++;
            }
        }
        return cnt;
    }
};