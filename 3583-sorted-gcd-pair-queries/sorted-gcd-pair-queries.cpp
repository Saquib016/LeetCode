class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        // count numbers divisible by d
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cnt[d] += freq[m];
        }

        vector<long long> exact(mx + 1, 0);

        // inclusion exclusion
        for (int d = mx; d >= 1; d--) {
            exact[d] = cnt[d] * (cnt[d] - 1) / 2;

            for (int m = d * 2; m <= mx; m += d)
                exact[d] -= exact[m];
        }

        vector<long long> prefix;
        vector<int> value;

        long long sum = 0;

        for (int d = 1; d <= mx; d++) {
            if (exact[d] == 0) continue;

            sum += exact[d];
            prefix.push_back(sum);
            value.push_back(d);
        }

        vector<int> ans;

        for (long long q : queries) {
            int idx = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(value[idx]);
        }

        return ans;
    }
};