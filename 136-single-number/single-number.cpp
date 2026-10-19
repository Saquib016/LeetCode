class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int prev  =0;

        for(int i = 0;i<nums.size();i++){
            prev = nums[i]^prev;
        }
        return prev;
    }
};