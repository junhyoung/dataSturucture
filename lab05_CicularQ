/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : Lab05
* Description: Circular Queue 만들기
* Algorithm : Queue에 enqueue를 할때 size를 넘어가면 처음으로 돌아와 비어있으면 enqueue를 한다.
* Variables:
* x:
**********************************************************/
#include"circularQ.h"

void main() {
	Queue Q(3); // Queue 사이즈는 3
	int select = 0;


	while (1) {
		cout << "1. enque 2. deque 3. Display Q 4. Exit" << endl;
		cin >> select;
		switch (select) {
		case 1: {
			char temp;
			cin >> temp;
			Q.enq(temp);
			break;
		}
		case 2: {
			cout << Q.deq() << endl;
			break;
		}
		case 3: {
			Q.printQ();
			break;
		}
		case 4:
			exit(1);
		}
	}
}
