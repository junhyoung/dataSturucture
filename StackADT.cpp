#include"Stack.h"
Stack::Stack(int size) :size(size)
{
	top = -1;
	arrayOfData = (int *)malloc(size*sizeof(int));
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

void Stack::push(int value) {
	if (isFull())
		cout << "Stack is Full" << endl;
	else
		arrayOfData[++top] = value;
}
int Stack::pop() {
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
	}
}
