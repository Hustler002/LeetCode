class Solution {
public:
    int find(vector<int>& temp, int target, int n){
        //sort(temp.begin(), temp.end());
        int m = temp.size();
        int idx = -1;
        int low = 0, high = m-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(temp[mid] == target){
                idx = mid;
                break;
            }
            else if (temp[mid] > target)
                high = mid-1;
            else low = mid+1;
        }
        int left_val = temp[(idx-1+m)% m];
        int right_val = temp[(idx+1) % m];

        int dl = min(abs(temp[idx] - left_val), n - abs(temp[idx] - left_val));
        int dr = min(abs(temp[idx] - right_val), n - abs(temp[idx] - right_val));
        return min(dl, dr);
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(auto& j : queries){
            if(mpp[nums[j]].size() >= 2){
                int res = find(mpp[nums[j]] , j, n);
                ans.push_back(res);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};