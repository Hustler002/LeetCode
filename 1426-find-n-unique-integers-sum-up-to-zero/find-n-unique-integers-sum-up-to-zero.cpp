class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n==1) return {0};
        if(n==2) return {-1,1};
        if(n%2!=0){
            ans.push_back(-1);
            ans.push_back(0);
            ans.push_back(1);
            n=n-3;
        }
        else{
            ans.push_back(-1);
            ans.push_back(1);
            n=n-2;
        }
        
        int num = 2;
        for(int i = 1; i <= n/2; i++){
            ans.push_back(num);
            ans.push_back(-num);
            num++;
        }
        return ans;
    }
};