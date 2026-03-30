class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            auto iter = mp.find(target-nums[i]);
            if(iter != mp.end()) {
                ans.push_back(iter->second);
                ans.push_back(i);
                return ans;
            } else {
                mp.insert(make_pair(nums[i], i));
            }
        }
        return ans;

    }
};
