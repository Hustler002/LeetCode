class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(auto& sub : s){
            if(sub=='a' || sub=='e' || sub=='i' || sub=='o' || sub=='u')
                cnt++; 
        }
        if(cnt == 0) return false;
        //if(cnt%2==0) return true;
        return true;
    }
};