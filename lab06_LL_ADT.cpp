#include"linked.h"

List* qHead;
List* qTail;
List* sHead;

void List::push(char data) {
	List*temp = new List(data);
	if (sHead == NULL)
		sHead = temp;
	else {
		temp->next = sHead;
		sHead = temp;
	}
}
void List::pop(){
	List*temp = sHead;
	if (sHead == NULL)
	{
		cout << "Stack is Empty" << endl;
	}
	else {
		sHead = sHead->next;
		cout << temp->data << endl;
		delete temp;
	}

}
void List::printStack(){
	List* temp = sHead;
	if (sHead == NULL)
		cout << "Stack is Empty" << endl;
	while (temp) {
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << endl;
}
void List::enqueue(char data){
	List* temp = new List(data);
	if (qHead == 0) {
		qHead = qTail = temp;
	}
	else {
		qTail->next = temp;
		qTail = qTail->next;
	}
}
void List::dequeue(){
	List *temp = qHead;
	if (qHead == 0) {
		cout << "Queue is Empty" << endl;
	}
	else {
		cout << temp->data << endl;
		qHead = qHead->next;
		delete temp;
	}

}
void List::searchQueue(char data){
	List * temp = qHead;
	bool isT = true;
	while (temp) {
		if (temp->data == data) {
			isT = true;
			break;
		}
		else
			isT = false;
		temp = temp->next;
	}
	if (isT) {
		cout << data << " is in the queue" << endl;
	}
	else
		cout << data << " is not in the queue" << endl;
}
void List::PrintQueue(){
	List * temp = qHead;
	if (temp == NULL)
		cout << "Queue is Empty";
	while (temp) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
