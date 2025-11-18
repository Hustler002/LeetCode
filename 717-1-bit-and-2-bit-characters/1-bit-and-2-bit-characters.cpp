class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        for(i = 0; i < n-1; i++){
            if((bits[i] == 1 && bits[i+1] == 1) || (bits[i] == 1 && bits[i+1] == 0))
                i++;
        }
        if(i == n-1 && bits[n-1] == 0) return true;
         
        return false;
    }
};