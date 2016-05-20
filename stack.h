#include<iostream>
using namespace std;
class Stack {
private:
	int * arrayOfData;
	int top;
	const int size;
public:
	Stack(int size);
	virtual ~Stack();
	bool isFull() const;
	bool isEmpty() const;
	void push(int value);
	int pop();
	void print() const;

};
