class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tot = 0;
        for(int i = 0;i<nums.size();i++){
            tot += nums[i];
        }
        int rsum = tot;
        int lsum = 0;
        for(int i = 0;i<nums.size();i++){
            int val = nums[i];
            rsum-=val;
            if(lsum == rsum) return i;
            lsum += val;
        }
        return -1;
    }
};