class Solution {
public:
    bool checkDivisibility(int y) {
        int n=y;
        int prod=1,sum=0;
        int x;
        while(n!=0)
        {
            x=n%10;
            sum+=x;
            prod*=x;
            n/=10;
        }
        if(y%(sum+prod)==0) return true;
        return false;
    }
};