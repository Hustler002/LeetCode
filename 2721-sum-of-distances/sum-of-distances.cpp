class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        
        vector<long long> ans(n);
        
        for(auto& it : mpp){
            vector<int>& indices = it.second;
            long long total_sum = 0;
            
            for(int idx : indices){
                total_sum += idx;
            }
            
            long long left_sum = 0;
            long long m = indices.size();
            
            for(long long i = 0; i < m; i++){
                long long curr_idx = indices[i];
                
                long long right_sum = total_sum - left_sum - curr_idx;
                
                long long left_count = i;
                long long right_count = m - 1 - i;
                
                long long left_dist = (left_count * curr_idx) - left_sum;
                long long right_dist = right_sum - (right_count * curr_idx);
                
                ans[curr_idx] = left_dist + right_dist;
                left_sum += curr_idx;
            }
        }
        
        return ans;
    }
};