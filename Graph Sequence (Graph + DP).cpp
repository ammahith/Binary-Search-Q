#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxLength = 0;
    // Create a separate matrix to store the longest increasing path length
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    // Perform a depth-first search from each cell to find the longest increasing path
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maxLength = max(maxLength, dfs(matrix, dp, i, j));
        }
    }
    return maxLength;
}
int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int row, int col) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (dp[row][col] != 0) {
        return dp[row][col];
    }
    // Initialize the length of the longest increasing path for the current cell to 1
    dp[row][col] = 1;
    // Perform depth-first search in all four directions (top, left, bottom, right)
    vector<pair<int, int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

    for (auto dir : directions) {
        int newRow = row + dir.first;
        int newCol = col + dir.second;

        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[row][col]) {
            dp[row][col] = max(dp[row][col], 1 + dfs(matrix, dp, newRow, newCol));
        }
    }
    return dp[row][col];
}
int main() {
    vector<vector<int>> matrix = {
        {0, 2, 4, 3, 2},
        {7, 6, 5, 5, 1},
        {8, 9, 7, 18, 14},
        {5, 10, 11, 12, 13}
    };
    int maxLength = longestIncreasingPath(matrix);
    cout << maxLength << endl;
    return 0;
}