class Solution {
public:
    long long check(int a, int b, long long mid){
        long long ans = 0;
        ans = (mid/a) + (mid/b) - (mid/((a*b)/gcd(a,b)));
        return ans;
    }
    const int MOD = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long start = min(a,b);
        long long end = n*start;

        while(start <= end){
            long long mid = start + (end - start) / 2;

            if(check(a,b,mid) == n){
                if(mid%a == 0 || mid % b==0) return mid % MOD;
                end = mid;
            }
            else if(check(a,b,mid) > n){
                end = mid-1;
            }
            else 
                start = mid+1;
        }
        return -1;
    }
};

// 2 3 4 6 8 9 10 12 
// 4