class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans = {};
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        int first = -1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]==target) {
                first = mid;
                j = mid-1;}
            else if(nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        if(first ==-1) return {};
         i = 0;
         j = nums.size()-1;
        int last = -1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]==target) {
                last = mid;
                i = mid+1;}
            else if(nums[mid] > target) j = mid-1;
            else i = mid+1;
        }
        for(int i = first;i<=last;i++){
            ans.push_back(i);
        }
        return ans;
    }
};