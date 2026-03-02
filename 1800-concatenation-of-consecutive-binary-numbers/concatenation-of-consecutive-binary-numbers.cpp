class Solution {
public:
    
    // string int_to_binary(int i){
    //     string bin = "";
    //     int cnt = i;
    //     while(i>0){
    //         bin += i%2 +'0';
    //         i = i/2;
    //     }
    //     reverse(bin.begin(),bin.end());
    //     return bin;
    // }
    // long long binpow(long long a, long long b, long long mod) {
    //     long long res = 1;
    //     while (b > 0) {
    //         if (b & 1) res = (res * a) % mod;
    //         a = (a * a) % mod;
    //         b >>= 1;
    //     }
    //     return res;
    // }

    // int binary_to_decimal(string bin){
    //     int deci = 0;
    //     int n = bin.size();
    //     for(int exp = 0; exp < n; exp++){
    //         int power = binpow(2,exp,MOD);
    //         deci = (deci+ ((power% MOD)*(bin[n-exp-1] -'0')) % MOD) % MOD;
    //     }
    //     return deci;
    // }
    int MOD = 1e9+7;
   
    int concatenatedBinary(int n) {
        //string conc = "";
        long res = 0;
        for(int i = 1; i <= n; i++){
            int digits = log2(i) + 1;
            res = (((res<<digits) % MOD ) + i ) % MOD;
            
        }
        return res;
    }
};