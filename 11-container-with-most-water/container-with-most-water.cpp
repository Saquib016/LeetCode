class Solution {
  public:
    int maxArea(vector<int> &arr) {
        // code here
        int maxArea = 0;
        int area=1;
        int i = 0;
        int j = arr.size()-1;
        while(i<j && j<arr.size()){
            area = min(arr[i],arr[j])* (j-i);
            maxArea = max(maxArea,area);
            if(arr[i]>=arr[j]) j--;  // the bigger one got advantage and get fixed cause we are not using its full potential just imagine 
            else if(arr[i]<arr[j]) i++;
            
        }
        return maxArea;
    }
};