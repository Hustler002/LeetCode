class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;

        int power = 0;
        int num = n;
        while(num){
            num /=2;
            power++;
        }
        int ans = pow(2,power);
        return ans;
    }
};