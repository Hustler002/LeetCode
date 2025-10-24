class Solution {
public:
    bool is_Beautiful(int num){
        vector<int> dig(10,0);

        while(num>0){
            int digit = num%10;
            if(digit==0) return false;
            dig[digit]++;
            num = num/10;
        }
        for(int i=1; i <= 9; i++){
            if(dig[i] != i && dig[i] > 0) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for(int i = n+1; i <= 1224444; i++){
            if(is_Beautiful(i)){
                return i;
            }
        }
        return 0;
    }
};
// 1000000
// 1224444