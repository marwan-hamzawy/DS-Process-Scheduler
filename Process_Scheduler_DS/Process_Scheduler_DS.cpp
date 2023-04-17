#include<iostream>
#include"PriorityQueue.h"

using namespace std;

int main() {
	PriorityQueue<int> pq;
	pq.enqueue(5, 2);
	pq.enqueue(10, 1);
	pq.enqueue(15, 3);
	int last = pq.print();
}