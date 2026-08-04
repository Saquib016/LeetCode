class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        
        // Step 1: Sort the numbers to make tracking linear
        sort(nums.begin(), nums.end());
        vector<int> list;
        
        // Step 2: Iterate and fill in all gaps between sequential elements
        for (int i = 1; i < nums.size(); i++) {
            int expected = nums[i - 1] + 1;
            
            // While there is a gap between the expected number and the current number
            while (expected < nums[i]) {
                list.push_back(expected);
                expected++;
            }
        }
        return list;
    }
};
