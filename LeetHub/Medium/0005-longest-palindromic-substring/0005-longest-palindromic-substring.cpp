class Solution {
public:
    string longestPalindrome(string s) {
        int mxLen = 1, start = 0;

        for (int i = 0; i < s.length(); ++i) {
            getMxPalindromeLen(s, i, i, start, mxLen);
            getMxPalindromeLen(s, i, i + 1, start, mxLen);
        }

        return s.substr(start, mxLen);
    }

    void getMxPalindromeLen(string &s, int l, int r, int &start, int &mxLen) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            --l; ++r;
        }

        if (r - l - 1 > mxLen) {
            mxLen = r - l - 1;
            start = l + 1;
        }
    }
};