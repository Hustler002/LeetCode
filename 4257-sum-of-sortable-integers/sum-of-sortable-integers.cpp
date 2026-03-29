class Solution {
public:
    bool is_sorted(vector<int> temp){
        int drop = 0;
        int n = temp.size();
        for(int i = 0; i < n; i++){
            if(temp[i] > temp[(i+1) % n]) drop++;
        }
        return drop <=1;
    }


    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        // Handle k = 1
        bool flag = true;
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] < nums[i]){
                flag = false;
                break;
            }
        }
        if(flag) sum += 1;

        // Handle divisors k from 2 to n
        for(int k = 2; k <= n; k++){
            if(n % k == 0){
                bool valid = true;
                int prev_max = -1;
                for(int i = 0; i < n; i+=k){
                    vector<int> temp(k,0);
                    int mini = INT_MAX;
                    int maxi = -1;

                    for(int j = 0; j < k; j++){
                        temp[j] = nums[i+j];
                        mini = min(mini, temp[j]);
                        maxi = max(maxi, temp[j]);  
                    }

                    if(!is_sorted(temp) || mini < prev_max){
                        valid = false;
                        break;
                    }
                    prev_max = maxi;
                }
                if(valid) sum +=k;
            }
        }
        return sum;
    }
};