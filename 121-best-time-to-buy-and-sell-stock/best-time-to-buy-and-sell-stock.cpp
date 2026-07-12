class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int i = 0;
        int j = 1;

        int result = 0;

        while(j < prices.size()){

            if(prices[j] > prices[i]){
                result = max(result, prices[j]-prices[i]);
            }
            else{
                i = j;
            }

            j++;
        }

        return result;
    }
};