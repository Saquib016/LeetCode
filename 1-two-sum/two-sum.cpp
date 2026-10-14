class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i = 0;i<nums.size();i++){
            int curr = nums[i];
            int ans = target - curr;
            if(seen.find(ans)!=seen.end()) return {seen[ans],i};
            seen[curr] = i;
        }
        return {};

    }
};