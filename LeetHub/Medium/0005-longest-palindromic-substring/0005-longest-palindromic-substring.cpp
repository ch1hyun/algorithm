class Solution {
public:
    bool memo[1000][1000];
    string longestPalindrome(string s) {
        string ans = "";
        memset(memo, false, sizeof(memo));

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                int len = j - i + 1;
                if (isPalindrome(s.substr(i, len)) && ans.length() < len) {
                    ans = s.substr(i, len);
                } 
            }
        }

        return ans;
    }

    bool isPalindrome(string target) {
        int i = 0, j = target.length() - 1;

        while (i <= j) {
            if (memo[i][j]) return true;
            if (target[i] != target[j]) return false;
            memo[i++][j--] = true;
        }

        return true;
    }
};