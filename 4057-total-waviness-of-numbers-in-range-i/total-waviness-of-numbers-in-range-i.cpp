class Solution {
public:
    int find_waviness(int n){
        int cnt = 0;
        string num = to_string(n);
        int sz = num.size();
        for(int i = 1; i < sz-1; i++){
            if(num[i] > num[i-1] && num[i] > num[i+1]){
                cnt++;
            }
            else if(num[i] < num[i-1] && num[i] < num[i+1]) cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int wavi = 0;
        for(int i = num1; i <= num2; i++){
            wavi += find_waviness(i);
        }
        return wavi;
    }
};