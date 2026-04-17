class Solution {
public:
    int mirror(int num){
        if(num < 10) return num;
        string s = to_string(num);
        reverse(s.begin(), s.end());
        num = stoi(s);
        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = n;
        unordered_map<int,int> mpp;

        for(int i = n-1; i >= 0; i--){
            
            int num = nums[i];
            int rev = mirror(num);
            
            if(mpp.find(rev) != mpp.end()){
                int dist = abs(mpp[rev] - i);
                //if(dist == 0) continue;
                mini = min(mini , abs(mpp[rev] - i));
            }
            mpp[nums[i]] = i;
        }
        return mini==n?-1:mini;
    }
};