class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto& it : nums){
            vector<int> temp;
            while(it > 0){
                int d = it%10;
                it = it/10;
                temp.push_back(d);
            }
            int m = temp.size();
            for(int i = m-1; i >= 0; i--){
                ans.push_back(temp[i]);
            }
            
        }
        return ans;
    }
};