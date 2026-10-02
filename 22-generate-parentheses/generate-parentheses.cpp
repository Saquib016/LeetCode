class Solution {
public:

    void solve(int n, int open, int close, string current, vector<string>& ans) {

        // agar n pairs complete ho gaye
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        // opening bracket laga sakte hain
        if (open < n) {
            solve(n, open + 1, close, current + "(", ans);
        }

        // closing bracket tabhi laga sakte hain
        // jab opening brackets zyada hain
        if (close < open) {
            solve(n, open, close + 1, current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};