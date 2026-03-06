class Solution {
public:
    bool checkZeroOnes(string s) {
        int zero = 0, one = 0;

        int n = s.size();

        for(int i = 0; i < n;){
            char curr = s[i];
            int cnt = 0;
            bool flag = false;
            if(s[i] == '1') flag = true;
            while(i < n && s[i] == curr){
                cnt++;
                i++;
            }
            if(flag == true) one = max(one,cnt);
            else if(flag == false) zero = max(zero,cnt);
        }
        cout<<one<< " "<<zero<<endl;
        return one > zero;
    }
};