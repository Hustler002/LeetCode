class Solution {
public:
    int minOperations(string s) {
        int pos = 0;
        int ans = 0;
        for(auto it : s){
            pos = it - 'a';
            ans = max(ans, (26-pos)%26);
        }
        return ans;
    }
};