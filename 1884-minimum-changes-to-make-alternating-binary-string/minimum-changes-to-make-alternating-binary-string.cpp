class Solution {
public:
    int minOperations(string s) {
        char curr = '1';
        int n = s.size();
        int cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != curr){
                cnt1++;
                // s[i] = curr == '1' ? '0' : '1';
            }
            curr = curr == '1' ? '0' : '1';
        }

        curr = '0';
        int cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != curr){
                cnt2++;
                // s[i] = curr == '1' ? '0' : '1';
            }
            curr = curr == '1' ? '0' : '1';
        }
        return min(cnt1,cnt2);
    }
};