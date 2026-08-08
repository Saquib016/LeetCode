class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        if(x<0) return false;
        while(x!=0){
            int temp = x%10;
            arr.push_back(temp);
            x=x/10;
        }
        int i = 0;
        int j = arr.size()-1;
        while(i<=j){
            if(arr[i]!=arr[j]) return false;
            i++;j--;
        }
        return true;
        
    }
};