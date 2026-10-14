// Here We use Frequency Array so that its easy to count nums.
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int twice = 0;
        int miss = 0;
       vector<int> freq(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i = 1;i<=nums.size();i++){
            if(freq[i]>1) twice = i;
            else if( freq[i]==0) miss = i;
        }
  return {twice,miss};
    }
};
