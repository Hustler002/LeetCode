class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        int sum = nums[0];
        while(j < n && nums[j] == nums[j-1]+1){
            sum += nums[j];
            j++;
        }

        int ans = sum;

        // while(j < n){
        //     if(nums[j] >= sum) ans = min(ans,nums[j]);
        //     j++;
        // }

        sort(nums.begin(), nums.end());
        int i = 0, curr = 0;
        while(i < n){
            if(nums[i] < sum){
                i++;
                continue;
            }
            if(nums[i] > sum){
                return sum;
            }
            if(nums[i] == sum){
                curr = sum;
                i++;
                while(i < n){
                    if(nums[i] == curr + 1){
                        curr = nums[i];
                    } 
                    else if (nums[i] != curr) {
                        break;
                    }
                    i++;
                }
                return curr+1;
            }
        }
        return sum;
    }
};