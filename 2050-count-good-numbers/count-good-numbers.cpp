class Solution {
public:
    long long mod = 1000000007;

    long long power(long long base, long long exp) {
        long long ans = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % mod;
            }

            base = (base * base) % mod;
            exp /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long a = power(5, even);
        long long b = power(4, odd);

        return (a * b) % mod;
    }
};