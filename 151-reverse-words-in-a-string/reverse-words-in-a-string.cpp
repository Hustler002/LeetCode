class Solution {
public:
    string reverseWords(string s) {
        string res = "";

        int n = s.size();

        int i = n-1;
        string temp = "";
        while(i >= 0){
            if(s[i] == ' '){
                if(temp.empty()){
                    i--;
                    continue;
                }
                else {
                    reverse(temp.begin(), temp.end());
                    res += temp;
                    res.push_back(' ');
                    temp = "";
                }
            }    
            else temp.push_back(s[i]);     
            i--; 
        }
        reverse(temp.begin(), temp.end());
        if(!temp.empty()) res += temp;
        n = res.size();
        i = n-1;
        while(res[i] == ' ') {
            res.pop_back();
            i--;
        }
        return res;
    }
};