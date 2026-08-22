class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prd = 1;
        int temp = n;
        while (n>0){
            int dig = n%10;
            sum+=dig;
            prd*=dig;
            n = n/10;
        }
        cout<<sum<<endl<<prd;
        if(temp%(sum+prd)==0) return true;
        else return false;
    }
};