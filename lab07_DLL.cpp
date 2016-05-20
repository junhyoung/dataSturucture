/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : HW04
* Description: Doubly Linked List
* Algorithm : - 삽입 : 리스트가 비었을경우 노드를 헤드,테일 선언, 헤드앞에삽입할경우 노드의 prev는 0, 노드와 헤드 연결, 노드를 헤드로 정의, 중간에 삽입할경우 위치에넣고 앞으 노드와 노드, 뒤의 노드와 노드를 연결, 꼬리일 경우 노드의 next에 0, 노드와 테일 연결
- 검색 : 앞에서 부터 데이터를 비교하여 있으면 노드, 없으면 0를 반환
- 삭제 : 검색을 통해 찾은 노드가 헤드이면 다음 노드의 prev를 0, 노드를 헤드로 선언, 중간일경우 앞뒤 노드를 연결,  마지막일경우 마지막의 전노드의 next 0 설정
- forward : head를 통해 앞에서부터 검색
- backward : tail을 통해뒤에서부터 검색
- Quit : exit를 통하여 종료
* Variables: - Node 클래스 : 리스트의 각 노드의 정보를 저장하는 변수
- List 클래스 : 헤드와 테일, ADT함수를 저장하는 변수
- head : 리스트의 head를 저장하는 변수
- tail : 리스트의 tail을 저장하는 변수
- next : 노드의 다음 노드주소 저장 변수
- prev : 노드의 이전 노드주소 저장 변수
- data : 숫자 값 저장
- name : 이름 저장
**********************************************************/
#include<iostream>
#include<string>

using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* prev;
	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

class List {
public:
	Node* head;
	Node* tail;

	List() {
		head = NULL;
		tail = NULL;
	}

	void insert(Node* temp) {
		Node *p;
		Node* q;
		p = q = head;
		if (head) {
			if (head->data > temp->data) {
				temp->next = head;
				head->prev = temp;
				head = temp;
			}
			else {
				while (p->data < temp->data && q != NULL) {
					p = q;
					q = q->next;
				}
				if (q == NULL || q == head) {
					p->next = temp;
					temp->prev = p;
					tail = temp;
				}
				else {
					p->next = temp;
					q->prev = temp;
					temp->next = q;
					temp->prev = p;
				}
			}
		}
		else {
			head = temp;
			tail = temp;
		}
	}
	Node* find(int num) {
		Node* p;
		Node* q;
		p = q = head;
		if (head == NULL)
			cout << "List is Empty" << endl;
		else if (num==1) {
			return head;
		}
		else {
			while (num--) {
				p = q;
				q = q->next;
			}
			return p;
		}
	}
	void insert_after(Node* n, int num) {
		Node* p = find(num);
		Node* q = p->next;
		
		n->next = q;
		n->prev = p;
		q->prev = n;
		p->next = n;
		
	}
	void insert_before(Node* n, int num) {
		Node* p = find(num);
		Node* q = p->prev;

		n->next = p;
		n->prev = q;
		q->next = n;
		p->prev = n;

	}
	void Delete(int num) {
		
		Node* q = find(num);
		if (q) {

			if (q->next == NULL)
			{
				if (q->prev == NULL) {
					head = tail = NULL;
				}
				else {
					(q->prev)->next = NULL;
					tail = (q->prev);
				}
			}
			else if (q->prev == NULL) {
				if (q->next == NULL) {
					head = tail = NULL;
				}
				else {
					(q->next)->prev = NULL;
					head = q->next;
				}
			}
			else {
				Node* r = q->next;
				Node* p = q->prev;
				r->prev = p;
				p->next = r;
			}
			delete q;
			cout << num << " is delete" << endl;
		}
		else
			cout << num << " is not found" << endl;
	}
	void backword() {
		if (head) {
			Node* p = tail;
			while (p) {
				cout << p->data << " ";
				p = p->prev;
			}
			cout << endl;
		}
		else
			cout << "List is empty" << endl;
	}
	void forward() {
		Node* p = head;
		if (head) {
			while (p) {
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
		else
			cout << "List is empty" << endl;
	}
	void Quit() {
		exit(1);
	}
};

void main() {
	List* DLL = new List();
	while (1) {
		cout << "(1.insert, 2.forward, 3.insert_after, 4.insert_before, 5.find_Nth, 6.quit)" << endl;
		int sel;
		int num;
		int nth;
		cin >> sel;
		switch (sel)
		{
		case 1:
			cin >> num;
			DLL->insert(new Node(num));
			break;
		case 2:
			DLL->forward();
			break;
		case 3:
			cout << "Nth" << endl;
			cin >> nth;
			cout << "num" << endl;
			cin >> num;
			DLL->insert_after(new Node(num),nth);
			break;
		case 4:
			cout << "Nth" << endl;
			cin >> nth;
			cout << "num" << endl;
			cin >> num;
			DLL->insert_before(new Node(num), nth);
			break;
		case 5:
			cin >> num;
			cout << DLL->find(num)->data << endl;
			break;
		case 6:
			DLL->Quit();
			break;
		}
	}
}
