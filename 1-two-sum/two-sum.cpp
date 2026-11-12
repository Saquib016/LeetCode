class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index;
        for(int i = 0;i<nums.size();i++){
            index[nums[i]] = i;
        }
        for(int i = 0;i<nums.size();i++){
            if(index.contains((target-nums[i])) && i != index[target-nums[i]]) return {i,index[target-nums[i]]};
        }
        return {};
    }
};