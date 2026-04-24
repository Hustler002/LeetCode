class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r= 0, e = 0;
        for(auto& it : moves){
            if(it == 'L') l++;
            else if(it == 'R') r++;
            else e++;
        }
        if(l>=r) return (l+e-r);
        return r+e-l;
    }
};