#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to calculate the minimum number of dice throws required
int minDiceThrows(vector<vector<int>>& board, vector<pair<int, int>>& snakes, vector<pair<int, int>>& ladders) {
    int N = board.size();
    // Create a visited array to keep track of visited positions on the board
    vector<bool> visited(N + 1, false);
    // Initialize the queue for BFS traversal
    queue<pair<int, int>> q; // (position, dice throws)
    q.push({ 1, 0 }); // Start from position 1 with 0 dice throws

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int pos = curr.first;
        int diceThrows = curr.second;
        // If we reach the final position, return the number of dice throws
        if (pos == N)
            return diceThrows;
        // Mark the current position as visited
        visited[pos] = true;

        // Explore all possible moves from the current position
        for (int i = 1; i <= 6; i++) {
            int nextPos = pos + i;

            // If the next position is within the board limits
            if (nextPos <= N) {
                // If the next position is a snake or ladder, adjust the next position accordingly
                for (auto snake : snakes) {
                    if (snake.first == nextPos)
                        nextPos = snake.second;
                }
                for (auto ladder : ladders) {
                    if (ladder.first == nextPos)
                        nextPos = ladder.second;
                }

                // If the next position is not visited, enqueue it with the updated dice throws
                if (!visited[nextPos])
                    q.push({ nextPos, diceThrows + 1 });
            }
        }
    }
    // If the final position is not reachable, return -1
    return -1;
}
int main() {
    int N = 36; // Size of the board
    // Snakes configuration (head and tail positions)
    vector<pair<int, int>> snakes = { {17, 7}, {21, 3}, {27, 9}, {35, 19} };
    // Ladders configuration (start and end positions)
    vector<pair<int, int>> ladders = { {4, 14}, {9, 31}, {20, 38}, {28, 84}, {40, 59}, {51, 67}, {63, 81}, {71, 91} };
    // Construct the board
    vector<vector<int>> board(N + 1, vector<int>());
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 6 && i + j <= N; j++) {
            board[i].push_back(i + j);
        }
    }

    int minThrows = minDiceThrows(board, snakes, ladders);

    cout << "Minimum number of dice throws required: " << minThrows << endl;
    return 0;
}
