class Solution {
public:
    int n;
    typedef long long ll;
    vector<vector<ll>> memo;
    long long solve(vector<int>& nums, int trend, int i){
        if(i == n){
            if(trend ==3){
                return 0;// no more elemnts left reached to the end
            }
            else{
                return LLONG_MIN; //invalid value
            }
        }
        
        if(memo[i][trend] != LLONG_MIN){
            return memo[i][trend];
        }
        
        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        
        //skip
        if(trend == 0){
            skip = solve(nums, 0, i+1);
        }

        if(trend == 3){
            take = nums[i];
        }
        if(i+1 < n){
            int curr = nums[i];
            int next = nums[i+1];
            if(trend == 0 && next > curr){
                take  = max(take, curr + solve(nums, 1, i+1));
            }
            else if(trend == 1){
                if(next > curr){
                    take = max(take, curr + solve(nums, 1 , i+1));
                }
                else if(next < curr){
                    take = max(take, curr + solve(nums, 2, i+1));
                }
            }
            else if(trend == 2){
                if(next < curr){
                    take = max(take, curr + solve(nums, 2 , i+1));
                }
                else if(next > curr){
                    take = max(take, curr + solve(nums, 3, i+1));
                }
            }
            else if(trend == 3 && next > curr){
                take = max(take, curr + solve(nums, 3, i+1));
            }
        }

        return memo[i][trend] = max(take,skip);
    }
    
    long long maxSumTrionic(vector<int>& nums) {
        int trend = 0;
        n = nums.size();
        memo.assign(n+1, vector<ll>(4, LLONG_MIN));
        return solve(nums,trend,0);
    }
};