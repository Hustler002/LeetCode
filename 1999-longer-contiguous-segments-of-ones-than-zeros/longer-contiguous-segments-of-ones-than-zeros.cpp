class Solution {
public:
    bool checkZeroOnes(string s) {
        int zero = 0, one = 0;

        int n = s.size();
        int i = 0;
        while(i < n){
            char curr = s[i];
            int cnt = 0;
            bool flag = false;
            if(s[i] == '1') flag = true;
            while(i < n && s[i] == curr){
                cnt++;
                i++;
            }
            if(flag) one = max(one,cnt);
            else zero = max(zero,cnt);
        }
        return one > zero;
    }
};