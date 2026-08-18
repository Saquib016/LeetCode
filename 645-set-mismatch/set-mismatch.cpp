class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n + 1, 0);
        int duplicate = -1;
        int missing = -1;

        // Count the frequency of each number
        for (int num : nums) {
            counts[num]++;
        }

        // Find the duplicate and missing numbers
        for (int i = 1; i <= n; i++) {
            if (counts[i] == 2) {
                duplicate = i;
            } else if (counts[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};
