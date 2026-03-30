class Solution {
public:
    void back_track(vector<int> &nums, int i, vector<int> &subset, vector<vector<int>> &res) {
        //basecase
        if( i>=nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        back_track(nums, i+1, subset, res);
        subset.pop_back();
        back_track(nums, i+1, subset, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        back_track(nums, 0, subset, res);
        return res;
    }
};
