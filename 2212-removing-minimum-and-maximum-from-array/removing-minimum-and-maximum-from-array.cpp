class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = INT_MAX;
        int mx = INT_MIN;

        int minIndex = -1;
        int maxIndex = -1;

        // Find min, max and their indices
        for (int i = 0; i < n; i++) {
            if (nums[i] < mn) {
                mn = nums[i];
                minIndex = i;
            }

            if (nums[i] > mx) {
                mx = nums[i];
                maxIndex = i;
            }
        }

        // Make minIndex the smaller index
        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        // Option 1: remove both from the left
        int left = maxIndex + 1;

        // Option 2: remove both from the right
        int right = n - minIndex;

        // Option 3: remove min from left and max from right
        int both = (minIndex + 1) + (n - maxIndex);

        return min({left, right, both});
    }
};