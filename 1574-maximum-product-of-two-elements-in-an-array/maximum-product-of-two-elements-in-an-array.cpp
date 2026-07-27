class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int maxpr = 1;
        for(int i = 0;i<2;i++){
            maxpr*=nums[i]-1;
        }
        return maxpr;
    }
};