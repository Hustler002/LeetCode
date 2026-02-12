class Solution {
public:
    int longestBalanced(string s) {
        
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            unordered_map<char,int> mpp;
            for(int j = i; j < n; j++){
                mpp[s[j]]++;
                bool flag = true;
                int common = 0;
                for(auto& it : mpp){
                    if(common == 0) common = it.second;

                    else if(it.second != common){
                        
                        flag = false;
                        break;
                    }
                }
                if(flag) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};