class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto str: strs) {
            string key(26, 0);
            for(char c : str) {
                key[c-'a']++;
            }
            mp[key].push_back(str);
        } 
        vector<vector<string>> ans;
        ans.reserve(mp.size());
        for(auto &[_, group]: mp) {
            ans.push_back(std::move(group));
        }
        return ans;
    }
};
