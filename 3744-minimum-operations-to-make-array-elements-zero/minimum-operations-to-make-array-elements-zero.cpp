// class Solution {
// public:
//     long long minOperations(vector<vector<int>>& queries) {
//         int ans = 0;
//         for(auto &it : queries){
//             priority_queue<int,vector<int>> pq;
//             int l = it[0];
//             int r = it[1];
//             for(int i = l; i<= r; i++){
//                 pq.push(i);
//             }
//             while(!pq.empty() && pq.size()>1){
//                 int x = pq.top(); pq.pop();
//                 int y = pq.top(); pq.pop();
//                 x = x/4;
//                 y = y/4;
//                 ans++;
//                 if(x!=0)pq.push(x);
//                 if(y!=0)pq.push(y);
//             }
//             while(!pq.empty()){
//                 int x = pq.top(); pq.pop();
//                 x /=4;
//                 ans++;
//                 if(x!=0)pq.push(x);
//             }
//         }
//         return ans;
//     }
// };





//OPTIMIZEDDDDDDDDDDDDD

class Solution {
public:
#define ll long long
    ll minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for(auto &it : queries){
            ll l = it[0];
            ll r = it[1];
            ll step = 1;
            ll L = 1;
            ll R = 4*L-1;
            ll op = 0;
            while(L<=r){
                int start = max(L,l);
                int end = min(R,r);
                if(start <= end){
                    int num = end - start+1;
                    op += step*num;
                }
                step++;
                L = 4*L;
                R = 4*L-1;
            }
             
            ans += (op+1)/2;
        }
        return ans;
    }
};