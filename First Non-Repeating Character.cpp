#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<char> findFirstNonRepeatingChar(string S) {
    vector<char> result;
    queue<char> nonRepeatingChars;
    vector<int> charCount(26, 0);

    for (char c : S) {
        charCount[c - 'a']++;

        while (!nonRepeatingChars.empty() && charCount[nonRepeatingChars.front() - 'a'] > 1) {
            nonRepeatingChars.pop();
        }

        if (charCount[c - 'a'] == 1) {
            nonRepeatingChars.push(c);
        }

        if (!nonRepeatingChars.empty()) {
            result.push_back(nonRepeatingChars.front());
        }
        else {
            result.push_back('0');
        }
    }

    return result;
}

int main() {
    string S;
    cout << "Enter the stream of characters: ";
    cin >> S;

    vector<char> firstNonRepeatingChars = findFirstNonRepeatingChar(S);

    cout << "First non-repeating characters for each index: ";
    for (char c : firstNonRepeatingChars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}