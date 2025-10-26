class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n);
        string str = "";
        for(auto& it: s){
            if(it != '0') str.push_back(it);
        }
          return stoll(str);
    }
};