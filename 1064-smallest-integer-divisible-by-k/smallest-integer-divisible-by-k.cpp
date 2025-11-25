class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unsigned long long n = 1;
        int len = 1;
        while(len<1e5){
            if(n % k == 0){
                return len;
            }
            n = (n*10 + 1)%k;
            len++;
        }
        return -1;
    }
};