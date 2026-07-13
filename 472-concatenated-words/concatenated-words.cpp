class Solution {
public:
    unordered_set<string> dict;

    bool dfs(string &word, int index, vector<int> &dp) {

        if(index == word.size())
            return true;

        if(dp[index] != -1)
            return dp[index];

        string temp;

        for(int i = index; i < word.size(); i++) {

            temp += word[i];

            if(dict.count(temp)) {

                if(dfs(word, i + 1, dp))
                    return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        for(auto &w : words)
            dict.insert(w);

        vector<string> ans;

        for(auto &word : words) {

            dict.erase(word);          // Don't use the word itself

            vector<int> dp(word.size(), -1);

            if(dfs(word, 0, dp))
                ans.push_back(word);

            dict.insert(word);
        }

        return ans;
    }
};