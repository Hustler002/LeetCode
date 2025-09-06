#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;

        for (auto &it : queries) {
            long long l = it[0];
            long long r = it[1];

            long long sum = 0;
            long long low = 1;   // start of current block (4^{k-1})
            int k = 1;
            while (low <= r) {
                long long high;
                if (low > (LLONG_MAX / 4)) high = LLONG_MAX;
                else high = low * 4 - 1;

                long long a = max(low, l);
                long long b = min(high, r);
                if (a <= b) {
                    sum += (b - a + 1) * 1LL * k;
                }

                if (low > (LLONG_MAX / 4)) break;
                low *= 4;
                ++k;
            }

            res += (sum + 1) / 2;
        }

        return res;
    }
};
