class Solution {
public:
    int memo[21][21];
    bool isMatch(string s, string p) {
        // memset(memo, -1, sizeof(memo));
        //return topdown(0, 0, s, p);

        memset(memo, 0, sizeof(memo));
        return bottomup(s, p);
    }

    bool topdown(int i, int j, string &s, string &p) {
        if (memo[i][j] != -1) return memo[i][j];

        bool ans = false;

        if (j == p.length()) {
            if (i == s.length()) ans = true;
        } else {
            bool fm = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

            if (j + 1 < p.length() && p[j + 1] == '*') {
                ans = (topdown(i, j + 2, s, p) || (fm && topdown(i + 1, j, s, p)));
            } else {
                ans = fm && topdown(i + 1, j + 1, s, p);
            }
        }

        return memo[i][j] = ans;
    }

    bool bottomup(string &s, string &p) {
        memo[s.length()][p.length()] = true;

        for (int i = s.length(); i >= 0; --i) {
            for (int j = p.length() - 1; j >= 0; --j) {
                bool fm = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

                if (j + 1 < p.length() && p[j + 1] == '*') {
                    memo[i][j] = (memo[i][j + 2] || (fm && memo[i + 1][j]));
                } else {
                    memo[i][j] = (fm && memo[i + 1][j + 1]);
                }
            }
        }

        return memo[0][0];
    }
};