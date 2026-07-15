class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        for(int i= 1;i<=2*n;i++){
            if(i%2==0) sumEven+=i;
            else sumOdd+=i;
        }
        int x = min(sumEven, sumOdd);
        if(sumEven % x == 0 && sumOdd % x == 0) return x;
        for(int i=x/2;i>1;i--){
            if(sumEven%i==0 && sumOdd%i==0) return i;
        }
        return 1;
    }
};