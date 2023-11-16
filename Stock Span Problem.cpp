#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> calculateStockSpans(const vector<int>& prices) {
    int n = prices.size();
    vector<int> spans(n, 1);
    stack<int> stk;

    stk.push(0);
    for (int i = 1; i < n; i++) {
        while (!stk.empty() && prices[i] >= prices[stk.top()]) {
            stk.pop();
        }

        spans[i] = stk.empty() ? (i + 1) : (i - stk.top());
        stk.push(i);
    }

    return spans;
}

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the stock prices for each day: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<int> spans = calculateStockSpans(prices);

    cout << "Stock Spans: ";
    for (int span : spans) {
        cout << span << " ";
    }
    cout << endl;

    return 0;
}