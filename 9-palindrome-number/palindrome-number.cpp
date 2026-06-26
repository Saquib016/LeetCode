class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;
        int y = x;
        int digit;
        if(x<0) return false;
        while (x!=0){
            if(x!=0){
                digit = x%10;
                x=x/10;
            }
            if(rev>INT_MAX/10 || (rev == INT_MAX/10 && digit >7)) return 0;
            if(rev<INT_MIN/10 || (rev == INT_MIN/10 && digit<-8)) return 0;
            rev = rev*10+digit;
        }
        if(y==rev) return true;
        else return false;
    }
};