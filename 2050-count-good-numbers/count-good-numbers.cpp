class Solution {
public:
    const int M = 1e9+7;
    long long pownum(long long a,long long b){
        if(b==0) return 1;
        long long power = pownum(a,b/2);
        long long result = power* power%M;
        if(b%2==1) result = (result*a)%M ;
        return result%M;
    }
    int countGoodNumbers(long long n) {
        long long res = (pownum(5,(n+1)/2)*pownum(4,n/2));
        return res % M;
    }
};