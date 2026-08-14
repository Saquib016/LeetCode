class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        int max_len = 0;
        int freq[26] = {0}; // Correctly initialized to 0

        for (int j = 0; j < s.size(); ++j) {
            // 1. Add the current character to the window
            freq[s[j] - 'a']++;

            // 2. Shrink the window from the left if the character count exceeds 2
            while (freq[s[j] - 'a'] > 2) {
                freq[s[i] - 'a']--;
                i++;
            }

            // 3. Update the maximum valid window size found so far
            max_len = max(max_len, j - i + 1);
        }

        return max_len;
    }
};
