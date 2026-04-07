class Solution {
public:
    // Format: "<len>#<str><len>#<str>..."
    string encode(vector<string>& strs) {
        string encoding;
        for (auto& str : strs) {
            encoding += to_string(str.size()) + '#' + str;
        }
        return encoding;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (s[j] != '#') j++;          // find delimiter
            int len = stoi(s.substr(i, j - i)); // parse length
            result.push_back(s.substr(j + 1, len));
            i = j + 1 + len;                  // advance past '#' + string
        }
        return result;
    }
};