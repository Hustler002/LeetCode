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

// T.C. = O(one * zero * limit)
// S.C. = O(one * zero)

// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     long long t[1001][1001][2];

//     long long solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit){
//         if(zerosLeft == 0 && onesLeft == 0) return 1;

//         if(t[onesLeft][zerosLeft][lastWasOne] != -1) return t[onesLeft][zerosLeft][lastWasOne];

//         long long res = 0;
        
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
//         return t[onesLeft][zerosLeft][lastWasOne] = res;
//     }

//     int numberOfStableArrays(int zero, int one, int limit) {
//         memset(t, -1, sizeof(t));

//         long long startWithOne = solve(one,zero, false, limit);

//         long long startWithZero = solve(one, zero, true, limit);

//         return (startWithOne + startWithZero) % MOD;
//     }
// };




// Bottom- UP   (Approach - 3)

// class Solution {
// public:
//     int MOD = 1e9 + 7;
//     int t[1001][1001][2];

//     int numberOfStableArrays(int zero, int one, int limit) {
//         memset(t, 0 , sizeof(t));

//         t[0][0][0] = 1;
//         t[0][0][1] = 1;

//         for(int onesLeft = 0 ; onesLeft <= one; onesLeft++){
//             for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++){

//                 if(onesLeft == 0 && zerosLeft == 0) continue;

//                 int result = 0;

//                 for(int len = 1; len <= min(zerosLeft, limit); len++){
//                     result = (result + t[onesLeft][zerosLeft-len][0]) % MOD;
//                 }
//                 t[onesLeft][zerosLeft][1] = result;

//                 result = 0;
//                 for(int len = 1; len <= min(onesLeft, limit); len++){
//                     result = (result + t[onesLeft - len][zerosLeft][1]) % MOD;
//                 }
//                 t[onesLeft][zerosLeft][0] = result;

//             }
//         }

//         int startWithOne = t[one][zero][false];
//         int startWithZero = t[one][zero][true];

//         return (startWithOne + startWithZero) % MOD;
//     }
// };


// Optmizedd  (Approach - 4)

class Solution {
public:
    int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> t(zero+1, vector<vector<int>>(one+1, vector<int>(2,0)));

        for(int i =0; i <= min(zero,limit); i++) t[i][0][0] = 1;

        for(int j = 0; j <= min(one,limit); j++) t[0][j][1] = 1;

        for(int i = 0; i <= zero; i++){
            for(int j = 0; j <= one; j++){
                if(i==0 || j== 0) continue;

                t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % MOD;

                if(j-1 >= limit){
                    t[i][j][1] = (t[i][j][1] - t[i][j-1-limit][0] + MOD) % MOD;
                }

                t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % MOD;

                if(i-1 >= limit){
                    t[i][j][0] = (t[i][j][0] - t[i-1-limit][j][1] + MOD) % MOD;
                }

            }
        }

        int startWithOne = t[zero][one][0];
        int startWithZero = t[zero][one][1];

        return (startWithOne + startWithZero) % MOD;
    }
};