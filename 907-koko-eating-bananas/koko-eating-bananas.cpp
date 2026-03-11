class Solution {
public:
    bool check(int k, int h, vector<int> piles){
        long long cnt = 0;
        for(auto& it : piles){
            cnt += it / k;
            if(it % k != 0) cnt++;
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1, high = -1;

        
        for(auto& it : piles){
            //low = min(low,it);
            high = max(high, it);
        }
        int ans = high;

        while(low <= high){
            int mid = low + (high-low) / 2;

            if(check(mid,h,piles)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};