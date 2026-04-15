class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int posNums = nums.size() + 1;
        unordered_set<int> uniques;
         // Amortized constant time for insertion => O(n)
        for(auto const &num : nums){
            uniques.insert(num);
        }
        
        //amaortized constant time for search => O(length of array)
        for(int i=1; i <= posNums; i++){
            if(uniques.find(i) == uniques.end())
                return i;
        }
        return -1;
    }
};