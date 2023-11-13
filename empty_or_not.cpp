#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> pqueueGFG;
	pqueueGFG.push(1);

	// Priority Queue becomes 1 check if it is empty or not
	if (pqueueGFG.empty())
	{
		cout << "Empty or true";
	}
	else
	{
		cout << "Contains element or False";
	}
	return 0;
}
