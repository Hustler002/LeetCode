class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int cnt = 0;
        bool flag = false;
        for(int i = 0; i < n; i++){
            while(i< n && s[i] == '1'){
                flag = true;
                i++;
            }
            if(flag) cnt++;
            flag = false;
        }
        return cnt<=1;
    }
};