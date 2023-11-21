#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
int minimumSmoke(const std::vector<int>& mixtures) {
    int n = mixtures.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    std::vector<std::vector<int>> smoke(n, std::vector<int>(n));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; k++) {
                int currSmoke = smoke[i][k] + smoke[k + 1][j] + mixtures[i] * mixtures[k + 1];
                if (dp[i][j] > dp[i][k] + dp[k + 1][j] + currSmoke) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + currSmoke;
                    smoke[i][j] = (mixtures[i] + mixtures[k + 1]) % 100;
                }
            }
        }
    }
    return dp[0][n - 1];
}
int main() {
    int n;
    std::cin >> n;
    std::vector<int> mixtures(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mixtures[i];
    }
    int minSmoke = minimumSmoke(mixtures);
    std::cout << minSmoke << std::endl;
    return 0;
}