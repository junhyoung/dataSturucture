/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : Lab06
* Description: Linked list stack & Queue
* Algorithm :
* Variables:
**********************************************************/
#include"linked.h"

void main() {
	int sel;
	char d;
	List S;
	List Q;
	cout << "1. Push 2. Pop 3. PrintStack 4. Enqueue 5. Dequeu 6. Search Queue 7.PrintQueue" << endl;
	while (cin >> sel) {
		switch (sel) {
		case 1:
			cin >> d;
			S.push(d);
			break;
		case 2:
			S.pop();
			break;
		case 3:
			S.printStack();
			break;
		case 4:
			cin >> d;
			Q.enqueue(d);
			break;
		case 5:
			Q.dequeue();
			break;
		case 6:
			cin >> d;
			Q.searchQueue(d);
			break;
		case 7:
			Q.PrintQueue();
			break;
		}
	}

}
