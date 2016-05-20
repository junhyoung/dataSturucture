#include<iostream>
using namespace std;
class Stack {
private:
	char * arrayOfData;
	int top;
	const int size;
public:
	Stack(int size);
	virtual ~Stack();
	bool isFull() const;
	bool isEmpty() const;
	void push(char value);
	char pop();
	void print() const;

};
Stack::Stack(int size) :size(size)
{
	top = -1;
	arrayOfData = (char *)malloc(size*sizeof(char));
}

Stack::~Stack() {
	free(arrayOfData);
}

bool Stack::isFull() const {
	return top >= size - 1 ? true : false;
}
bool Stack::isEmpty() const {
	return top < 0 ? true : false;
}

void Stack::push(char value) {
	if (isFull())
		cout << "Stack is Full" << endl;
	else
		arrayOfData[++top] = value;
}
char Stack::pop() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return -1;
	}
	return arrayOfData[top--];
}

void Stack::print() const {
	if (isEmpty())
		cout << "Stack is Empty" << endl;
	else {
		for (int i = 0; i <= top; i++)
			cout << arrayOfData[i] << " ";
		cout << endl;
	}
}

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
			rear = (rear + 1);
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
			front = (front + 1);
			return result;
		}
	}
	void printQ() {
		int temp = front;
		for (int i = temp; temp != rear; i++) {
			cout << Q[(temp++)] << " ";
		}
		cout << endl;
	}

	bool isEmpty() {
		if (rear == -1)
			return true;
		return front == rear;
	}
	bool isFull() {
		if ((rear + 1) == size ) {
			return true;
		}
		else return false;
	}
};
