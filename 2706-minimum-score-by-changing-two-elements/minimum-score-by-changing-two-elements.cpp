class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0; // Changing 2 elements can make all 3 equal

        // Sort in descending order: nums[0] is max, nums[n-1] is min
        sort(nums.begin(), nums.end(), greater<>());

        // Case 1: Change the 2 smallest elements (ignore nums[n-1] and nums[n-2])
        int case1 = nums[0] - nums[n - 3];

        // Case 2: Change the 2 largest elements (ignore nums[0] and nums[1])
        int case2 = nums[2] - nums[n - 1];

        // Case 3: Change 1 largest and 1 smallest element (ignore nums[0] and nums[n-1])
        int case3 = nums[1] - nums[n - 2];

        return min({case1, case2, case3});
    }
};
