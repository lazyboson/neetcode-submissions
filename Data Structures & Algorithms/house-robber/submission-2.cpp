class Solution {
public:
    int robNew(vector<int> &dp, vector<int> &num, int n) {
        if(n > num.size()-1)
            return 0;
        if(n == num.size()-1)
            return num[n];
        if(dp[n] != INT_MIN)
            return dp[n];
        dp[n] = max(num[n]+robNew(dp, num, n+2), num[n+1]+robNew(dp, num, n+3));
        return dp[n];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(101, INT_MIN);
        return robNew(dp, nums, 0);

    }
};
