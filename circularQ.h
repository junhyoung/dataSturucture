#include<iostream>
using namespace std;

class Queue {
public:
	int size;
	int front;
	int rear;
	char *Q;
	Queue(int size1) :size(size1) {
		Q = (char*)malloc(sizeof(char)*size);
		front = -1;
		rear = -1;
	}
	Queue CreateQ() {
		front = -1;
		rear = -1;
	}
	void enq(char item) {
		if (isFull())
			cout << "Queue is Full" << endl;
		else {
			Q[rear] = item;
			rear = (rear + 1) % size;
		}
	}
	char deq() {
		char result;
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return -1;
		}
		else {
			result = Q[front];
			front = (front + 1) % size;
			return result;
		}
	}
	void printQ() {
		int temp = front;
		for (int i = temp; temp != rear; ((i + 1) % size)) {
			cout << Q[(temp++) % size] << " ";
		}
		cout << endl;
	}

	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		if (front == (rear + 1) % size) {
			return true;
		}
		else return false;
	}
};
