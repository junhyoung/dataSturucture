#include <iostream>
using namespace std;
class List {
public:
	char data;
	List *next;
	List(char data) {
		this->data = data;
		next = NULL;
	};
	List() {

	}
	void push(char data);
	void pop();
	void printStack( );
	void enqueue(char data);
	void dequeue();
	void searchQueue(char data);
	void PrintQueue();
};
