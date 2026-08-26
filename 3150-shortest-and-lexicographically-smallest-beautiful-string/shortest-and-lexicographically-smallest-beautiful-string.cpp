class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, count = 0;
        string result = "";

        for (int right = 0; right < n; ++right) {
            // Expand the window by counting '1's
            if (s[right] == '1') {
                count++;
            }

            // Shrink the window from the left as long as we have exactly k '1's
            while (count == k) {
                // Get the current valid substring
                string current_sub = s.substr(left, right - left + 1);

                // Update result if it's shorter, or lexicographically smaller if lengths match
                if (result == "" || current_sub.size() < result.size() || 
                   (current_sub.size() == result.size() && current_sub < result)) {
                    result = current_sub;
                }

                // Move left pointer to find a potentially shorter substring
                if (s[left] == '1') {
                    count--;
                }
                left++;
            }
        }
        return result;
    }
};
