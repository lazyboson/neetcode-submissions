class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> count;
      for(auto const &num: nums) {
        count[num]++;
      }  
      vector<vector<int>> collector(nums.size() +1);
      for(auto itr: count) {
        collector[itr.second].push_back(itr.first);
      }
      vector<int> ans;
      for(int i=collector.size()-1; i>0; i--) {
        for(auto const data: collector[i]) {
            ans.push_back(data);
            if(ans.size() == k) {
              return ans;
            }
        }
      }
        return ans;
    }
};
