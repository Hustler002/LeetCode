class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        if(n == 1) return 0;
        int cnt = 0;
        
        for(int i = 1; i < n; i++){
            if(abs(s[i-1] - s[i]) <= 1){
                cnt++;
                s[i] = '!';
            }
        }
        cout<<s<<endl;
        return cnt;
    }
};