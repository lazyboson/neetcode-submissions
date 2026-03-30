class Solution {
public:
    int  climb(vector<int> &dp, vector<int> &cost, int n) {
        if(n > cost.size() -1)
            return 0;
        if(dp[n] != INT_MAX)
            return dp[n];
        dp[n] = min(dp[n], min(cost[n] + climb(dp, cost, n+1), cost[n] + climb(dp, cost, n+2)));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(101, INT_MAX);
         climb(dp, cost,  0);
        return min(dp[0], dp[1]);
    }
};
