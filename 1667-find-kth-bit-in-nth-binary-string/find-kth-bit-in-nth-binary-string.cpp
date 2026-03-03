class Solution {
public:
    string inverse(string prev){
        for(int i = 0; i < prev.size(); i++){
            if(prev[i] == '1') prev[i] = '0';
            else prev[i] = '1';
        }
        return prev;
    }
    char findKthBit(int n, int k) {
        string prev = "0";
        if(n==1) return '0';
        string curr = "";
        for(int i = 1; i < n; i++){
            string invert = inverse(prev);
            reverse(invert.begin(),invert.end());
            curr = prev + "1" + invert;
            prev = curr;
        }
        //int sz = curr.size();
        return curr[k-1];
    }
};