class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0; // Edge case: already at the end

        // 1. Your original map logic (fixed 'nums' typo to 'arr')
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++){
            mpp[arr[i]].push_back(i);
        }

        // 2. BFS Setup instead of a single 'i' variable
        queue<int> q;
        q.push(0);
        
        vector<bool> visited(n, false);
        visited[0] = true;
        
        int steps = 0; // Your steps variable
        
        // 3. Modified while loop to process level by level (BFS)
        while(!q.empty()){
            int size = q.size();
            
            // Process all nodes at the current step count
            while(size--) {
                int curr = q.front();
                q.pop();
                
                // If we reached the last index, return the current step count
                if (curr == n - 1) return steps;
                
                // Jump to i - 1
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                
                // Jump to i + 1
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                
                // Jump to j where arr[i] == arr[j]
                for (int next_idx : mpp[arr[curr]]) {
                    if (!visited[next_idx]) {
                        visited[next_idx] = true;
                        q.push(next_idx);
                    }
                }
                
                // CRITICAL: Clear the map for this value to prevent Time Limit Exceeded (TLE)
                mpp.erase(arr[curr]); 
            }
            steps++; // Increment steps after processing a full level
        }
        
        return 0;
    }
};