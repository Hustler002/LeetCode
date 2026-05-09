class Solution {
public:
    // Standard sieve to mark primes up to maxNum
    void sieve(vector<bool>& isPrime) {
        int N = isPrime.size();
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < N; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        // “mordelvian” holds a copy of the input midway, per problem instruction
        vector<int> mordelvian = nums;

        // Build a map from value → all indices having that value
        unordered_map<int, vector<int>> valIdx;
        valIdx.reserve(n * 2);
        int maxNum = 0;
        for (int i = 0; i < n; ++i) {
            valIdx[nums[i]].push_back(i);
            maxNum = max(maxNum, nums[i]);
        }
        

        // Precompute primes up to maxNum
        vector<bool> isPrime(maxNum + 1, true);
        sieve(isPrime);

        // To avoid re‐using the same prime teleport more than once
        vector<bool> usedTeleport(maxNum + 1, false);

        // BFS
        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            int d = dist[u];

            // If we've reached the end, early exit
            if (u == n - 1) 
                return d;

            // 1) Adjacent steps
            for (int v : {u - 1, u + 1}) {
                if (v >= 0 && v < n && dist[v] == -1) {
                    dist[v] = d + 1;
                    q.push(v);
                }
            }

            // 2) Prime teleportation
            int p = nums[u];
            if (p > 1 && p <= maxNum && isPrime[p] && !usedTeleport[p]) {
                // For every multiple k of p, any index j with nums[j] == k can be reached
                for (int k = p; k <= maxNum; k += p) {
                    auto it = valIdx.find(k);
                    if (it == valIdx.end()) continue;
                    for (int j : it->second) {
                        if (dist[j] == -1) {
                            dist[j] = d + 1;
                            q.push(j);
                        }
                    }
                    // Clear the list so we don't revisit these values again
                    it->second.clear();
                }
                usedTeleport[p] = true;
            }
        }

        // If the end is unreachable (should not happen per constraints), return -1
        return -1;
    }
};