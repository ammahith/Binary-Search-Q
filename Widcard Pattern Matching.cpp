#include <iostream>
#include <vector>

bool isMatch(const std::string& s, const std::string& p) {
    int m = s.length();
    int n = p.length();

    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    // Empty pattern matches empty string
    dp[0][0] = true;

    // Empty pattern matches with '*'
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }
    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*' || p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = false;
            }

            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j] || dp[i][j - 1] || dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}
int main() {
    std::string s, p;
    std::cin >> s >> p;
    bool match = isMatch(s, p);
    std::cout << (match ? "true" : "false") << std::endl;
    return 0;
}