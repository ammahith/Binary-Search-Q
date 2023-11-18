#include <iostream>
using namespace std;
typedef long long ll;

ll MOD(string num, int mod)
{
	ll res = 0;

	for (int i = 0; i < num.length(); i++)
		res = (res * 10 + num[i] - '0') % (mod - 1);

	return res;
}
ll ModExponent(ll a, ll b, ll m)
{
	ll result;
	if (a == 0)
		return 0;
	else if (b == 0)
		return 1;
	else if (b & 1)
	{
		result = a % m;
		result = result * ModExponent(a, b - 1, m);
	}
	else {
		result = ModExponent(a, b / 2, m);
		result = ((result % m) * (result % m)) % m;
	}
	return (result % m + m) % m;
}
int main()
{
	ll a = 3;
	// String input as b is very large
	string b = "100000000000000000000000000";
	ll m = 1000000007;
	ll remainderB = MOD(b, m);

	cout << ModExponent(a, remainderB, m) << endl;

	return 0;
}