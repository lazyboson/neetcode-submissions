class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto const num : nums) {
            count[num]++;
        }

        vector<vector<int>> ans(nums.size() + 1); 
        for (auto const& [val, freq] : count) {
            ans[freq].push_back(val);
        }

        vector<int> res;
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (k <= 0) break;

            for (int m = 0; m < ans[i].size() && k > 0; m++) {
                res.push_back(ans[i][m]);
                k--; 
            }
        }

        return res;
    }
};
