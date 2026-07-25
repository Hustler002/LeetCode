class Solution {
public:
    int maxProduct(int n) {
        string str = to_string(n);
        sort(str.begin(),str.end());
        int m = str.size();
        char c1 = str[m-1];
        char c2 = str[m-2];
        int a = c1 - '0';
        int b = c2 - '0';
        return a*b;
    }
};