class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st, res;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                st.insert(nums[i]^nums[j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(auto& it : st){
                res.insert(it^nums[i]);
            }
        }
        return res.size();
    }
};