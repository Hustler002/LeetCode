class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char,int> need;

        for(auto& c : t) need[c]++;

        int cnt = t.size();
        int len = INT_MAX;
        int start_idx = 0;
        int i = 0, j = 0;
        while(j<n){
            if(need[s[j]] > 0) cnt--;
            need[s[j]]--;
            j++;

            while(cnt==0){
                if(j-i<len){
                    len = j-i;
                    start_idx = i;
                }
                need[s[i]]++;

                if(need[s[i]] > 0) cnt++;
                i++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start_idx,len);
    }
};