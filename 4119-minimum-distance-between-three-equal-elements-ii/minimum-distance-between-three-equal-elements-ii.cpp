class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        int mini = INT_MAX;

        for(auto& it : mpp){
            vector<int> temp = it.second;
            int m = temp.size();
            if(m >= 3){
                int sum = INT_MAX;
                for(int j = 0; j < m-2; j++){
                    sum = min(sum, abs(temp[j] - temp[j+1]) + abs(temp[j+1] - temp[j+2]) + abs(temp[j+2]-temp[j]));
                }
                mini = min(mini,sum);
            }
            
        }
        return mini==INT_MAX? -1 : mini;
    }

};