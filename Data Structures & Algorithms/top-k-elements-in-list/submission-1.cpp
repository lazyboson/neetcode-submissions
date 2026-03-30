class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hash;

        for (auto it:nums) {
           hash[it]++;
        }
    // 1 2 2 3 3 3 4 4 4 k=1
        map<int,vector<int>, greater<int>> hash2;
    
        for (auto it:hash) {
            hash2[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (auto it:hash2) {
            for(auto it1:it.second) {
                ans.push_back(it1);
                k--;
                if (k==0) {
                    break;
                }
            }
            if (k == 0) {
                break;
            }
        }
        
        return ans;
    }
};