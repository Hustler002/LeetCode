class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0;
        int ans = 0;
        
        for(auto& str : bank){
            int cnt = 0;
            for(auto& it : str){
                if( it == '1') cnt++;
            }
            if(cnt!=0){
                if(prev!=0) ans += prev* cnt;
                prev = cnt;
            }
        }
        
        return ans;
    }
};