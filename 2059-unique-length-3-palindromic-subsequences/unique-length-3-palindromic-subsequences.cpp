class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> alp;
        for(auto& ch : s){
            alp.insert(ch);
        }
        int cnt = 0;
        int n = s.length();
        for(auto& it : alp){
            int i = 0;
            int j = s.length()-1;
            int start = -1, end = -1;
            while(i < n-1){
                if(s[i] == it){
                    start = i;
                    break;
                }
                i++;
            }
            while(j > 0){
                if(s[j] == it){
                    end = j;
                    break;
                }
                j--;
            }
            if(start == -1 || end == -1 || (start==end)) continue;
            set<char> btw;
            for(int k = start+1; k < end; k++){
                btw.insert(s[k]);
            }
            cnt += btw.size();
        }
        return cnt;

    }
};