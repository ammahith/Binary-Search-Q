#include <iostream>
#include <algorithm>
using namespace std;

static bool cmp(string a, string b) {
    return (a + b) >= (b + a);
}
string solve(vector<int>& nums) {
    vector<string> temp;
    for (int i : nums) {
        temp.push_back(to_string(i));
    }
    sort(temp.begin(), temp.end(), cmp);
    string res;
    for (string s : temp) {
        res += s;
    }
    return res;
}

int main() {
    vector<int> v = { 20, 8, 85, 316 };
    cout << solve(v);
}