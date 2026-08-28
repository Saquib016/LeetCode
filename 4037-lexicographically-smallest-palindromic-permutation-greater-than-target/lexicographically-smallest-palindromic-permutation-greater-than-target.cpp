class Solution {
   public:
    static auto lexPalindromicPermutation(std::string source,
                                          std::string target) -> std::string {
        const int length = static_cast<int>(source.size());

        std::vector<int> counts(ALPHABET_SIZE, 0);
        for (const char letter : source) {
            counts[static_cast<std::size_t>(letter - 'a')]++;
        }

        int odd_letter = -1;
        for (int idx = 0; idx < ALPHABET_SIZE; ++idx) {
            if (counts[static_cast<std::size_t>(idx)] % 2 == 1) {
                if (odd_letter >= 0) {
                    return "";
                }
                odd_letter = idx;
            }
            counts[static_cast<std::size_t>(idx)] /= 2;
        }

        const int half_len = length / 2;
        std::string result(static_cast<std::size_t>(length), 'a');
        if (odd_letter >= 0) {
            result[static_cast<std::size_t>(half_len)] =
                static_cast<char>('a' + odd_letter);
        }

        if (dfs(0, half_len, length, target, counts, result, false, false)) {
            return result;
        }
        return "";
    }

   private:
    static constexpr int ALPHABET_SIZE = 26;

    static auto dfs(int pos, int half_len, int length,
                    const std::string& target, std::vector<int>& counts,
                    std::string& result, bool greater_left, bool greater_right)
        -> bool {
        if (pos == half_len) {
            if (length % 2 == 1) {
                const char mid_char =
                    result[static_cast<std::size_t>(half_len)];
                const char target_mid =
                    target[static_cast<std::size_t>(half_len)];
                bool final_right = greater_right;
                if (mid_char > target_mid) {
                    final_right = true;
                } else if (mid_char < target_mid) {
                    final_right = false;
                }
                return greater_left || final_right;
            }
            return greater_left || greater_right;
        }

        const int mirror = length - 1 - pos;
        const int start =
            greater_left ? 0 : (target[static_cast<std::size_t>(pos)] - 'a');

        for (int letter = start; letter < ALPHABET_SIZE; ++letter) {
            if (counts[static_cast<std::size_t>(letter)] <= 0) {
                continue;
            }
            counts[static_cast<std::size_t>(letter)]--;

            const char placed = static_cast<char>('a' + letter);
            result[static_cast<std::size_t>(pos)] = placed;
            result[static_cast<std::size_t>(mirror)] = placed;

            const bool new_greater_left =
                greater_left ||
                (placed > target[static_cast<std::size_t>(pos)]);

            bool new_greater_right = greater_right;
            const char target_mirror = target[static_cast<std::size_t>(mirror)];
            if (placed > target_mirror) {
                new_greater_right = true;
            } else if (placed < target_mirror) {
                new_greater_right = false;
            }

            if (dfs(pos + 1, half_len, length, target, counts, result,
                    new_greater_left, new_greater_right)) {
                return true;
            }

            counts[static_cast<std::size_t>(letter)]++;
        }

        return false;
    }
};