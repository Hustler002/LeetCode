class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        vector<int> preb(n,0);
        vector<int> suffa(n,0);
        if(s[0] == 'b') preb[0] = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == 'b') preb[i] = preb[i-1]+1;
            else preb[i] = preb[i-1];
        }

        if(s[n-1] == 'a') suffa[n-1] = 1;
        for(int i = n-2; i >=0; i--){
            if(s[i] == 'a') suffa[i] = suffa[i+1] +1;
            else suffa[i] = suffa[i+1];
        }
        int ans = n;
        for(int i = 0; i < n; i++){
            ans = min(ans, preb[i] + suffa[i] -1);
        }
        return ans;
    }
};