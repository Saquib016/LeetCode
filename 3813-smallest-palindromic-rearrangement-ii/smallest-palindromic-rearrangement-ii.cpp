class Solution {
public:
    struct BigInt {
        static const uint64_t BASE = 1000000000ULL;
        vector<uint64_t> d;

        BigInt(uint64_t v = 0) { if (v) d.push_back(v); }

        void trim() {
            while (d.size() > 1 && d.back() == 0) d.pop_back();
            if (d.empty()) d.push_back(0ULL);
        }

        void mulSmall(uint64_t x) {
            uint64_t carry = 0;
            for (size_t i = 0; i < d.size(); i++) {
                __uint128_t cur = (__uint128_t)d[i] * x + carry;
                d[i] = (uint64_t)(cur % BASE);
                carry = (uint64_t)(cur / BASE);
            }
            while (carry) { d.push_back(carry % BASE); carry /= BASE; }
            if (d.empty()) d.push_back(0);
            trim();
        }

        void divSmall(uint64_t x) {
            uint64_t rem = 0;
            for (int i = (int)d.size() - 1; i >= 0; i--) {
                __uint128_t cur = (__uint128_t)rem * BASE + d[i];
                d[i] = (uint64_t)(cur / x);
                rem = (uint64_t)(cur % x);
            }
            trim();
        }

        bool geq(long long val) const {
            if (d.size() > 1) return true;
            return (long long)d[0] >= val;
        }

        long long smallValue() const { return (long long)d[0]; }
    };

    string smallestPalindrome(string s, long long k) {
        array<long long, 26> freq{};
        freq.fill(0);
        for (char c : s) freq[c - 'a']++;

        char middle = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) { middle = 'a' + i; break; }
        }

        array<long long, 26> half{};
        for (int i = 0; i < 26; i++) half[i] = freq[i] / 2;

        long long m = 0;
        for (int i = 0; i < 26; i++) m += half[i];

        BigInt cnt(1);
        long long placed = 0;
        for (int i = 0; i < 26; i++) {
            long long v = half[i];
            for (long long j = 1; j <= v; j++) {
                placed++;
                cnt.mulSmall((uint64_t)placed);
                cnt.divSmall((uint64_t)j);
            }
        }

        if (!cnt.geq(k)) return "";

        array<long long, 26> counts = half;
        long long remaining = m;
        string halfStr;
        halfStr.reserve(m);

        for (long long pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (counts[c] == 0) continue;

                BigInt candidate = cnt;
                candidate.mulSmall((uint64_t)counts[c]);
                candidate.divSmall((uint64_t)remaining);

                if (candidate.geq(k)) {
                    halfStr.push_back('a' + c);
                    counts[c]--;
                    remaining--;
                    cnt = candidate;
                    break;
                } else {
                    k -= candidate.smallValue();
                }
            }
        }

        string result = halfStr;
        if (middle) result.push_back(middle);
        string rev = halfStr;
        reverse(rev.begin(), rev.end());
        result += rev;
        return result;
    }
};