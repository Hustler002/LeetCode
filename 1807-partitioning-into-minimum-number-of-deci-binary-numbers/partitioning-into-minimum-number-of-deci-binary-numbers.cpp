class Solution {
public:
    int minPartitions(string n) {
        char maxi = 0;
        for(auto& it : n){
            maxi = max(maxi,it);
        }
        return maxi - '0';
    }
};