class Solution {
public:
    int gcd(int a,int b){
        while(b>0){
            int temp = b;
            b= a%b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
    
        int min = INT32_MAX;
        int max = INT32_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<min) min = nums[i];
            if(nums[i]>max) max = nums[i];
        }
            return gcd(max,min);
    }
};