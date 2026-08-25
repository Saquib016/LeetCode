#include <vector>
#include <unordered_set>

class Solution {
public:
    int missingMultiple(std::vector<int>& nums, int k) {
        // Use a hash set for O(1) lookups
        std::unordered_set<int> seen(nums.begin(), nums.end());
        
        // Check multiples sequentially: k * 1, k * 2, k * 3...
        int i = 1;
        while (true) {
            int multiple = k * i;
            // If the current multiple is not found, it's the missing one
            if (seen.find(multiple) == seen.end()) {
                return multiple;
            }
            i++;
        }
        return 0;
    }
};
