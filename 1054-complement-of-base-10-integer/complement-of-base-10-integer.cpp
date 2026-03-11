class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        string num = "";
        while(n>0){
            char c = n%2 + '0';
            char t;
            if(c== '1') t = '0';
            else t = '1';
            num.push_back(t);
            n = n/2;
        }
        //reverse(num.begin(),num.end());

        int ans = 0;

        for(int i = 0; i < num.size(); i++){
            if(num[i] == '1'){
                ans += pow(2,i);
            }
        }
        return ans;

    }
};