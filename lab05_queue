/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : Lab05
* Description: Stack과 Queue를 사용하여 abcde를 입력하고, ebcda를 출력하는 프로그램
* Algorithm : push a, enque b, enque c, enque d, push e , pop,deque, deque, deque, pop
* Variables:
* x:
**********************************************************/
#include"stack_q.h"

void main() {
	Stack S(2);
	Queue Q(3);
	int select = 0;


	while (1) {
		cout << "1. push 2. enque 3. pop 4. deque 5. Display Q 6. Display Stack 7. Exit" << endl;
		cin >> select;
		switch (select) {
		case 1: {
			char temp;
			cin >> temp;
			S.push(temp);
			break;
		}
		case 2: {
			char temp;
			cin >> temp;
			Q.enq(temp);
			break;
		}
		case 3: {
			cout << S.pop() << endl;
			break;
		}
		case 4: {
			cout << Q.deq() << endl;
			break;
		}
		case 5: {
			Q.printQ();
			break;
		}
		case 6: {
			S.print();
			break;
		}
		case 7:
			exit(1);
		}
	}
}
