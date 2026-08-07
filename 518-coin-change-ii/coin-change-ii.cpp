class Solution {
public:
    int change_help(int n,int W,vector<int> coins,vector<vector<int>>& dp){
        if(W==0) return 1;
        if(n==0 && W) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        else{
            if(W>=coins[n-1]){
                dp[n][W] =  change_help(n,W-coins[n-1],coins,dp)+change_help(n-1,W,coins,dp);
                return dp[n][W];
            }
            else {
               dp[n][W] = change_help(n-1,W,coins,dp);
                return dp[n][W];
            }
        }
        return 0;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int W = amount;
        vector<vector<int>> dp(n+1,vector<int> (W+1,-1));
        return change_help(n,W,coins,dp);
    }
};