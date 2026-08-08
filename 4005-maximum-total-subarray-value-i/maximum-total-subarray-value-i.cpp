class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max = INT_MIN;
        long long min = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(max<nums[i]) max = nums[i];
            if(min>nums[i]) min = nums[i];
        }
        long long ans = max-min;
        return k*ans;
    }
};