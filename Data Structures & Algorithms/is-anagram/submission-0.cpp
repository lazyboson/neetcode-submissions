class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for(auto first: s) {
            cnt[first-'a']++;
        }
        for(auto second: t) {
            cnt[second-'a']--;
        }
        for (auto const &c: cnt) {
            if (c != 0) {
                return false;
            }
        }
        return true;
    }
};
