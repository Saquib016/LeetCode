class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            int j = arr1.size()-1;
            int k = arr2.size()-1;
            if(arr1[j]>arr2[k]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }
        for(int x:arr2){
            arr1.push_back(x);
        }
        return arr1;
    }
};