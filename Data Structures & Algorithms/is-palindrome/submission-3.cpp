class Solution {
public:
    bool isPalindrome(string s) {     
       for(int i=0, j=s.size()-1; i<=j; ) {
            auto front = tolower(s[i]);
            auto back = tolower(s[j]);
            bool isFrontValid = false;
            bool isBackValid = false;
            if((front >= 'a' && front <= 'z') || (front >= '0' && front <= '9')) {
                  isFrontValid = true; 
            }
            if((back>='a' && back <= 'z') || (back >= '0' && back <= '9')) {
                isBackValid = true;
            }
            if(isFrontValid && isBackValid) {
                if(front != back)
                    return false;
                    i++;
                    j--;
            } else if (isFrontValid) {
                j--;
            } else {
                i++;
            }
       }
       return true;
    }
};
