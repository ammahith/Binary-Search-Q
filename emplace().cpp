// CPP program to illustrate Implementation of emplace() function

#include <iostream>
using namespace std;

int main()
{
	priority_queue<int> pq;
	pq.emplace(1);
	pq.emplace(2);
	pq.emplace(3);
	pq.emplace(4);
	pq.emplace(5);
	pq.emplace(6);
	// Priority queue becomes 1, 2, 3, 4, 5, 6

	cout << "Priority Queue = ";
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}