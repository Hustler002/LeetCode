class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(sum == 0){
            if(num==1) return "0";
            return ans;
        }
        if(sum > 9*num) return "";
        
        int nines = sum/9;
        int rem = sum%9;
        
        int zeros ;
        if(rem>0)
        zeros= num - nines-1;
        else zeros = num - nines;
        
            
        if(zeros<0) return ans;

        
        while(nines--){
            ans += '9';
        }
        if(rem>0) ans+= rem+'0';
        while(zeros--) ans += '0';
        return ans;
    }
};