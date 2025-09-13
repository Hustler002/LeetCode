class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        for(auto& ch : s){
            mpp[ch]++;
        }
        int vow = 0, conso = 0;
        for(auto& it : mpp){
            if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u'){
                vow = max(vow, it.second);
            }
            else{
                conso = max(conso, it.second);
            }
        }
        return vow+conso;
    }
};