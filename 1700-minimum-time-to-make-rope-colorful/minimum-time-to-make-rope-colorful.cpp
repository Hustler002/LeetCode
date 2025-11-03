class Solution {
public:
    int minCost(string s, vector<int>& nt) {
        int n = s.size();
        int time = 0;
        int total = accumulate(nt.begin(),nt.end(),0);
        int sum = 0;
        int i = 0;
        while(i<n){
            int maxi = nt[i];
            char curr = s[i];
            while(i < n && curr == s[i]){
                maxi = max(maxi,nt[i]);
                i++;
            }
            sum += maxi;
        }
        return total - sum;
    }
};