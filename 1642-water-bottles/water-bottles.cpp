class Solution {
public:
    int numWaterBottles(int nB, int nE) {
        int sum = nB;
        int total = 0;
        while(nB>=nE){
            total = (nB/nE)+(nB%nE);
            sum+=(nB/nE);
            nB = total;
        }
        return sum;
    }
};