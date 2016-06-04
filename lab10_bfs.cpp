/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : Lab10
* Description: BFS
* Algorithm : 
**********************************************************/
#include <iostream>
#include <fstream>

using namespace std;

#define max 8

int matrix[max][max] = {
	{ 0,1,0,0,1,0,0,0 },
	{ 1,0,1,0,1,0,0,0 },
	{ 0,1,0,1,0,1,0,0 },
	{ 0,0,1,0,0,0,0,0 },
	{ 1,1,0,0,0,1,0,0 },
	{ 0,0,1,0,1,0,1,0 },
	{ 0,0,0,0,0,1,0,1 },
	{ 0,0,0,0,0,0,1,0 }
};

class Node {
public:
	int vertex;
	Node *next;
	Node(int value) {
		vertex = value;
		next = 0;
	}
	friend class Graph;
};

class Graph {
private:
	Node *front;
	Node *rear;
public:
	Node *graph[max];
	bool visited[max];
	Graph() { front = 0; rear = 0; }
	void initGraph();
	void insertGraph(int num1, int num2);
	void enqueue(int);
	int dequeue();
	bool isEmpty();
	void displayQueue();
	//void searchQueue(char);
	void BFS(int v);
};

void Graph::initGraph() {
	for (int i = 0; i < max; i++) {
		graph[i] = 0;
		visited[i] = false;
	}
}

void Graph::insertGraph(int num1, int num2) {
	graph[num1]->vertex = num2;
}

void Graph::enqueue(int value) {
	Node *temp = new Node(value);

	if (front == 0) {
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}

int Graph::dequeue() {
	Node *p;
	int num;

	if (isEmpty()) {
		cout << "Queue empty";
		return 0;
	}

	num = front->vertex;
	p = front;

	if (front == rear) {
		front = 0;
		rear = 0;
	}
	else
		front = front->next;

	delete p;
	return num;
}

bool Graph::isEmpty() {
	if (front == 0) return true;
	else return false;
}

void Graph::displayQueue() {
	Node *p;

	if (!isEmpty()) {
		p = front;
		while (p) {
			cout << p->vertex << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "Queue is empty" << endl;
}
/*
void Graph::searchQueue(char value) {
Node *p;

if (!isEmpty()) {
p = front;
while (p != 0 && p->data != value) {
p = p->next;
}
if (p)
cout << p->data << " is in the queue." << endl;
else
cout << value << " is not in the list." << endl;
}
else
cout << "List is empty" << endl;
}
*/

char changeChar(int num) {
	if (num == 0) return 'S';
	if (num == 1) return 'A';
	if (num == 2) return 'B';
	if (num == 3) return 'C';
	if (num == 4) return 'D';
	if (num == 5) return 'E';
	if (num == 6) return 'F';
	if (num == 7) return 'G';
}


void Graph::BFS(int v) {
	Node *p;

	visited[v] = true;
	enqueue(v);
	cout << changeChar(v) << " ";

	while (front) {
		v = dequeue();
		for (p = graph[v]; p; p = p->next) {
			if (!visited[p->vertex]) {
				enqueue(p->vertex);
				visited[p->vertex] = true;
				cout << changeChar(p->vertex) << " ";
			}
		}
	}
}

void printAdjacentMatrix() {
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void main() {
	Graph *g = new Graph();
	Node *p = new Node(0);

	printAdjacentMatrix();
	cout << endl;

	for (int i = 0; i < max; i++) {
		int temp = 0;
		for (int j = 0; j < max; j++) {
			if (matrix[i][j] == 1) {
				(g->graph + temp)[i] = new Node(j);
				if (temp != 0)
					(g->graph + temp - 1)[i]->next = (g->graph + temp)[i];
				temp++;
			}
		}
	}

	for (int i = 0; i < max; i++)
		g->visited[i] = false;

	g->BFS(0);
	cout << endl;
}
