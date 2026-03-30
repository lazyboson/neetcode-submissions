class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
      
        for(auto str: strs) {
            vector<int> cnt(26, 0);
            for(int i=0; i<str.size(); i++) {
                cnt[str[i]-'a']++;
            }
            mp[cnt].push_back(str);
        } 
        vector<vector<string>> ans;
        for(auto m: mp) {
            ans.push_back(m.second);
        }
        return ans;
    }
};
