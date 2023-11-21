#include<vector>
#include<string>
#include <iostream>
using namespace std;

void fizzBuzz(int N)
{

	int count3 = 0;
	int count5 = 0;

	// Iterate from 1 to N
	for (int i = 1; i <= N; i++) {

		count3++;

		count5++;

		bool flag = false;

		if (count3 == 3) {
			cout << "Fizz";

			count3 = 0;
			flag = true;
		}

		if (count5 == 5) {
			cout << "Buzz";

			count5 = 0;
			flag = true;
		}

		if (!flag) {
			cout << i;
		}

		cout << " ";
	}
}

int main()
{
	int N = 15;
	fizzBuzz(N);

	return 0;
}
