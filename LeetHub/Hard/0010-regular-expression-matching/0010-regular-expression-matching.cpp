class Solution {
public:
    int memo[21][21];
    bool isMatch(string s, string p) {
        memset(memo, -1, sizeof(memo));

        return dp(0, 0, s, p);
    }

    bool dp(int i, int j, string &s, string &p) {
        if (memo[i][j] != -1) return memo[i][j];

        bool ans = false;

        if (j == p.length()) {
            if (i == s.length()) ans = true;
        } else {
            bool fm = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

            if (j + 1 < p.length() && p[j + 1] == '*') {
                ans = (dp(i, j + 2, s, p) || (fm && dp(i + 1, j, s, p)));
            } else {
                ans = fm && dp(i + 1, j + 1, s, p);
            }
        }

        return memo[i][j] = ans;
    }
};