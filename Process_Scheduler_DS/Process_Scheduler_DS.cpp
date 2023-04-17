#include<iostream>
#include"PriorityQueue.h"
#include"CircularQueue.h"

using namespace std;

int main() {
	/*PriorityQueue<int> pq;
	pq.enqueue(5, 2);
	pq.enqueue(10, 1);
	pq.enqueue(15, 3);
	int last = pq.print();*/

	CircularQueue<int, 5> cq;

	// Enqueue some elements.
	cq.enqueue(1);
	cq.enqueue(2);
	cq.enqueue(3);

	// Print the queue.
	cq.print();
}

