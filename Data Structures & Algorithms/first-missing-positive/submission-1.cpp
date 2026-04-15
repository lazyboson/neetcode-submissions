class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         int n = nums.size();

        // Phase 1: Place each number at its correct index
        // nums[i] should live at index nums[i]-1
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Phase 2: First index where nums[i] != i+1 is the answer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;  // All [1..n] present, so answer is n+1
    }
};