class Solution {
public:
    // Helper now takes the original vector by reference and uses index bounds
    int helper(const vector<int>& nums, int start, int end) {
        int prev1 = 0;
        int prev2 = 0;
        
        for (int i = start; i <= end; i++) {
            int curr = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge Case: If there is only 1 house, just rob it
        if (n == 1) return nums[0]; 
        
        // Case 1: Skip the first house (range: 1 to n-1)
        int f = helper(nums, 1, n - 1);
        
        // Case 2: Skip the last house (range: 0 to n-2)
        int l = helper(nums, 0, n - 2);
        
        return max(f, l);
    }
};
