class Solution {
public:
    int memo[205][205][205];
    const int MOD = 1e9 + 7;

    int dp(int i, int g1, int g2, const vector<int>& nums) {
        if (i == nums.size()) {
            // Both subsequences must be non-empty (g1 > 0) and have the same GCD
            return (g1 > 0 && g1 == g2) ? 1 : 0;
        }
        
        if (memo[i][g1][g2] != -1) {
            return memo[i][g1][g2];
        }
        
        long long ways = 0;
        
        // 1. Skip nums[i]
        ways = (ways + dp(i + 1, g1, g2, nums)) % MOD;
        
        // 2. Pick nums[i] in the first subsequence
        int next_g1 = (g1 == 0) ? nums[i] : std::gcd(g1, nums[i]);
        ways = (ways + dp(i + 1, next_g1, g2, nums)) % MOD;
        
        // 3. Pick nums[i] in the second subsequence
        int next_g2 = (g2 == 0) ? nums[i] : std::gcd(g2, nums[i]);
        ways = (ways + dp(i + 1, g1, next_g2, nums)) % MOD;
        
        return memo[i][g1][g2] = ways;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, 0, nums);
    }
};