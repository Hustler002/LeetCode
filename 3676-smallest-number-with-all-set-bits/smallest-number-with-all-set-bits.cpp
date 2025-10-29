class Solution {
public:
    int smallestNumber(int n) {
        int num = 1;
        int power = 1;
        while(num < n){
            num += pow(2,power);
            power++;
        }
        return num;
    }
};
//1 - 1 + 2^1
//11 - 3 + 2^2
// 111- 7 + 2^3
// 1111 - 15