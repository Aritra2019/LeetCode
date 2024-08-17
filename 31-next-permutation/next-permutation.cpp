class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        
        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        
        // If the array is in descending order, reverse it to get the smallest permutation
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 2: Find the smallest element larger than nums[idx] from the end
        int swapIdx = -1;
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swapIdx = i;
                break;
            }
        }
        swap(nums[idx], nums[swapIdx]);
        reverse(nums.begin() + idx + 1, nums.end());
    
    }
};