class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int i, int j, vector<int>& robot, vector<int>& fact){
        if(i == robot.size()) return 0;
        if(j == fact.size()) return 1e15;
        if(dp[i][j] != -1) return dp[i][j];
        long long take = abs(fact[j]-robot[i]) + solve(i+1, j+1, robot, fact);
        long long skip = solve(i, j+1, robot, fact);

        return dp[i][j] = min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> fact;
        for(auto & it : factory){
            int freq = it[1];
            while(freq--) fact.push_back(it[0]);
        }
        int m = robot.size();
        int n = fact.size();
        dp.assign(m, vector<long long> (n,-1));
        int i = 0;
        int j = 0;
        return solve(i,j, robot, fact);

    }
};