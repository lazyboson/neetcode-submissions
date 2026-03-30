class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        for(auto const &str: strs) {
            vector<int> cnt(26, 0);
            for(auto const s: str) {
                cnt[s-'a']++;
            }
            mp[cnt].push_back(str);
        }
        for(auto const itr: mp) {
            ans.push_back(itr.second);
        }
        return ans;
    }
};
