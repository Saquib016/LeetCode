class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        if(arr.size()==0) return 0;
        int inc = 1;
        int dec = 1;
        int ans = 1;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i]){
                inc++;
                dec = 1;
            }
            else if(arr[i-1]>arr[i]){
                inc= 1;
                dec++;
            }
            else if(arr[i-1]==arr[i]){
                inc =1;
                dec = 1;
            }
            ans = max(ans,max(inc,dec));
        }
        return ans;
    }
};