class Solution {
public:
    bool isPalindrome(string s) {
       string str;
       for(auto const &ch: s) {
        auto c = (char)tolower(ch);
        if((c >= 'a' && c <='z') || (c >= '0' && c <'9'))  {
                str += c;
            }
       } 
       cout << str << endl;
       
       for(int i=0, j=str.size()-1; i<=j; i++, j--) {
            if(str[i] != str[j])
                return false;
       }
       return true;
    }
};
