class Solution {
public:
    int mirror(int num){
        int ans = 0;
        while(num > 0){
            ans = ans*10 + (num % 10);
            num /= 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = n;
        unordered_map<int,int> mpp;
        mpp.reserve(n*2);
        for(int i = n-1; i >= 0; i--){
            int num = nums[i];
            int rev = mirror(num);
            
            if(mpp.find(rev) != mpp.end()){
                int dist = abs(mpp[rev] - i);
                mini = min(mini , abs(mpp[rev] - i));
            }
            mpp[nums[i]] = i;
        }
        return mini==n?-1:mini;
    }
};