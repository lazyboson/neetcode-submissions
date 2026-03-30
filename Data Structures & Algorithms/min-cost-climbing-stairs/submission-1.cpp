class Solution {
public:
    int climb(vector<int> &dp, vector<int> &cost, int n) {
        if(n > cost.size() -1)
            return 0;
        if(dp[n] != INT_MAX)
            return dp[n];
        dp[n] = min(dp[n], min(cost[n] + climb(dp, cost, n+1), cost[n] + climb(dp, cost, n+2)));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(101, INT_MAX);
        auto res1 = climb(dp, cost,  0);
       // vector<int> dp1(101, INT_MAX);
        auto res2 = climb(dp, cost, 1);
        return min(res1, res2);
    }
};
