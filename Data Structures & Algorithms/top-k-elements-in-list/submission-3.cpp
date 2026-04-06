class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) count[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [val, freq] : count)
            buckets[freq].push_back(val);

        vector<int> res;
        res.reserve(k);
        for (int i = buckets.size() - 1; i >= 0 && k > 0; i--) {
            for (int val : buckets[i]) {
                res.push_back(val);
                if (--k == 0) return res;
            }
        }
        return res;
    }
};