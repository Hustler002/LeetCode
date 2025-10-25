class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int cnt = 0;
        int loop = n/7;
        int rem = n % 7;
        for(int i = 1; i <=loop; i++){
            cnt++;
            for(int j = 1; j <= 7; j++){
                ans += cnt + j - 1;
            }
        } 
              
        for(int i = 1; i <= rem; i++){
            ans += cnt+i;
        }
        return ans;
    }
};