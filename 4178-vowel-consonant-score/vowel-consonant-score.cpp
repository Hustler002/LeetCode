class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(auto& it : s){
            if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'){
                v++;
            }
            else if(it>='a'&& it <= 'z'){
                c++;
            }
        }
        int ans = 0;
        if(c>0) ans = v/c;
        return ans;
    }
};