class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for(int i = 0;i<mat.size();i++){
            ans+=mat[i][i];
            ans+=mat[i][n-i-1];
            if(i == n-i-1) ans-=mat[i][n-i-1];
        }
        return ans;
    }
};