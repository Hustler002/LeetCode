class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto & it : nums) st.insert(it);

        int i = 1;
        while(i <= nums.size()){
            if(st.find(k*i) == st.end()) return k*i;
            i++;
        }
        return k*i;
    }
};