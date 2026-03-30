class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int maxNumber = 0;
       unordered_set<int> count;
       for(auto const &num: nums) {
            count.insert(num);
       }
       for(auto num: nums) {
        int currMax = 1;
        if(count.find(num-1) == count.end()) {
            while(count.find(++num) != count.end()) {
                currMax++;
            }
        }
        maxNumber = max(maxNumber, currMax);
       }
       return maxNumber;
    }
};
