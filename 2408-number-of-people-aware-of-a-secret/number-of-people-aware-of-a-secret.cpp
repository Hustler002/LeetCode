// Using Priority Queue
// O(N2*logN)



// class Solution {
// public:
//     int peopleAwareOfSecret(int n, int d, int f) {
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         int time = 1;
//         pq.push({ time+d, time + f});
//         time++;
//         n--;
//         while(n--){
//             vector<pair<int,int>> v;
//             while(!pq.empty()){
//                 int first = pq.top().first;
//                 int second = pq.top().second;
                
//                 if(first <= time && time < second){
//                     v.push_back({first,second});
                    
//                     pq.push({time+d,time+f});
//                     pq.pop();

//                 }
//                 else if(time == second){
//                     pq.pop();
//                     break;
//                 }
//                 else{
//                     break;
//                 }
                
//             }
//             for(auto& it : v) pq.push({it.first,it.second});
//             time++;
//         }
//         return pq.size();
//     }
// };



// Recursion + Memo
//O(N*(forget-delay))

// class Solution {
// public:
//     int MOD = 1e9+7;
//     vector<int> dp;
//     int solve(int day, int delay, int forget){
//         if(day==1) return 1;
//         //if(day<1) return 0;
//         if(dp[day] != -1) return dp[day];
//         int res = 0;
//         for(int d = day-forget+1; d <= day - delay; d++){
//             if(d>0)
//                 res = (res + solve(d, delay,forget)) % MOD;
//         }
//         return dp[day] = res;
//     }

//     int peopleAwareOfSecret(int n, int delay, int forget) {
//         int ans = 0;
//         dp.assign(n+1,-1);
//         for(int i = n-forget+1; i <= n; i++){
//             if(i>0)
//                 ans = (ans + solve(i,delay,forget)) % MOD;
//         }
//         return ans;
//     }
// };







//Bottom Up


class Solution {
public:
    int MOD = 1e9+7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1);
        dp[1] = 1;
        for(int day = 2; day <= n; day++){
            int cnt = 0;
            for(int d = day-forget+1; d <= day-delay; d++){
                if(d>0) cnt = (cnt + dp[d]) % MOD;
            }
            dp[day] = cnt;
        }

        int res = 0;
        for(int i = n-forget+1; i <= n; i++){
            if(i>0) res = (res + dp[i]) % MOD;
        }
        return res;
    }
};