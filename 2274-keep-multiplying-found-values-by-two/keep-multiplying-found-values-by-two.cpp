class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> numss;
        for(auto& it : nums) numss.insert(it);

        while(numss.find(original) != numss.end()){
            original *=2;

        }
        return original;
    }
};