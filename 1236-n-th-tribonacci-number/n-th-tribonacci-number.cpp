class Solution {
public:
    int tri_helper(int n,vector<int> &dp){
        if(n==0|| n==1) return n;
        else if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        dp[n] = tri_helper(n-1,dp)+tri_helper(n-2,dp)+tri_helper(n-3,dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return tri_helper(n,dp);
    }
};