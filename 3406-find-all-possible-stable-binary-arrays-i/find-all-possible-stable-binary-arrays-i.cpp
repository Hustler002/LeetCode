// Recursive Approach ( Approach - 1)

// class Solution {
// public:
//     int MOD = 1e9 + 7;
   
//     int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit){
//         if(zerosLeft == 0 && onesLeft == 0) return 1;
//         int res = 0;
        
//         // explore zeros
//         if(lastWasOne == true){
//             for(int len = 1; len <= min(limit,zerosLeft); len++){
//                 res = (res + solve(onesLeft, zerosLeft - len, false, limit)) % MOD;
//             }
//         }
//         else{
//             for(int len = 1; len <= min(limit,onesLeft); len++){
//                 res = (res + solve(onesLeft - len, zerosLeft, true, limit) % MOD);
//             }
//         }
//         return res;
//     }
//     int numberOfStableArrays(int zero, int one, int limit) {
//         int startWithOne = solve(one,zero, false, limit);

//         int startWithZero = solve(one, zero, true, limit);

//         return (startWithOne + startWithZero)% MOD;
//     }
// };





// Memo (Approach - 2)

//T.C. = O(one * zero * limit)
//S.C. = O(one * zero)

class Solution {
public:
    int MOD = 1e9 + 7;
    long long t[201][201][2];

    long long solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit){
        if(zerosLeft == 0 && onesLeft == 0) return 1;

        if(t[onesLeft][zerosLeft][lastWasOne] != -1) return t[onesLeft][zerosLeft][lastWasOne];

        long long res = 0;
        
        // explore zeros
        if(lastWasOne == true){
            for(int len = 1; len <= min(limit,zerosLeft); len++){
                res = (res + solve(onesLeft, zerosLeft - len, false, limit)) % MOD;
            }
        }
        else{
            for(int len = 1; len <= min(limit,onesLeft); len++){
                res = (res + solve(onesLeft - len, zerosLeft, true, limit) % MOD);
            }
        }
        return t[onesLeft][zerosLeft][lastWasOne] = res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));

        long long startWithOne = solve(one,zero, false, limit);

        long long startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % MOD;
    }
};

