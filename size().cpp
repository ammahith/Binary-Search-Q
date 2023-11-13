// C++ program to demonstrate the size() method of priority queue


#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<string> pqueue;

	// add items to priority_queue
	pqueue.push("Geeks");
	pqueue.push("for");
	pqueue.push("Geeks");
	pqueue.push("C++");

	// get the size of queue
	int size = pqueue.size();
	cout << "Size of the queue: " << size;

	return 0;
}
