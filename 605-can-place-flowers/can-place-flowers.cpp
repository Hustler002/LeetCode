class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int m = nums.size();
        int ans = 0;
        int cnt = 0;
        // for(int i = 0; i < m-1; i++){
        //     if(nums[i] == 0 && nums[i+1] == 0){
        //         cnt++;
        //         i++;
        //     }
        // }
        int i = 0;

        while(i < m && nums[i] == 0){
            i++;
            cnt++;
        }

        if(i==m){
            ans += (cnt+1) / 2;
            if(ans >= n) return true;
            else return false;
        }
        ans += (cnt)/2;
        cnt=0;
        int j = i+1;
        while(j<m){
            while(j < m && nums[j] == 0){
                j++;
                cnt++;
            }
            if(j < m && nums[j] == 1) ans += (cnt-1)/2;
            cnt=0;
            j++;
        }
        j = m-1;
        cnt = 0;
        while(j >= 0 && nums[j] == 0){
            j--;
            cnt++;
        }
        ans += (cnt)/2;
        cout<<ans<<endl;
        if(ans >= n) return true;
        return false;
    }
};