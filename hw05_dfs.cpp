/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : HW05
* Description: DFS
* Algorithm : adjacency List - 주어진 인접행렬을 데이터 타입이 Node인 링크드 리스트에 인접한 점을 연결하여 만든다.
			  DFS - 시작 정점 v에 방문후 v에 인접한 각 정점들에 대하여 dfs함수를 재귀적으로 호출한다. 모두 방문하면 종료한다.
* Variables: 
	matrix - 인접행렬을 저장하기 위한 변수
	Node *graph[8] - 인접행렬을 adjacency List로 저장하기위한 링크드 리스트
	bool visited[8] - 점에 방문했는지 확인하기위한 행렬
	void initGraph() - 그래프의 초기화를위한 함수
	void insertGraph(int num1, int num2) - 점을 adjacency List에 넣어주기위한 함수
	void dfs(int v) - DFS를 구하기위한 함수
	void printAdjacentMatrix() - Adjacency List 의 각 링크드 리스트를 출력해주기 위한 함수
	char change(int v) - 숫자를 각 점의 알파벳으로 변환하는 함수
**********************************************************/
#include<iostream>
#include<string>

using namespace std;
int matrix[8][8] = {
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
	Node *graph[8];
	bool visited[8];
	Graph() { front = 0; rear = 0; initGraph(); }
	void initGraph();
	void insertGraph(int num1, int num2);
	void enqueue(int);
	int dequeue();
	bool isEmpty();
	void displayQueue();
	//void searchQueue(char);
	void dfs(int v);
};

void Graph::initGraph() {
	for (int i = 0; i < 8; i++) {
		graph[i] = 0;
		visited[i] = false;
	}
}

void Graph::insertGraph(int num1, int num2) {
	graph[num1]->vertex = num2;
}

char change(int num) {
	switch (num) {
	case 0:
		return 'S';
	case 1:
		return 'A';
	case 2:
		return 'B';
	case 3:
		return 'C';
	case 4:
		return 'D';
	case 5: 
		return 'E';
	case 6:
		return 'F';
	case 7:
		return 'G';
	}
}


void Graph::dfs(int v) {
	Node *p;

	visited[v] = true;
	cout << change(v) << " ";

	
	for (p = graph[v]; p; p = p->next) {
		if (!visited[p->vertex]) {
			dfs(p->vertex);
		}
	}
	
}

void printAdjacentMatrix() {
	bool isFirst = true;
	for (int i = 0; i < 8; i++) {
		cout << change(i) << " : ";
		isFirst = true;
		for (int j = 0; j < 8; j++) {
			if (matrix[i][j]) {
				if (isFirst) {
					isFirst = false;
					cout << change(j);
				}
				else
					cout << "->" << change(j);
			}
		}
		printf("\n");
	}
}

void main() {
	Graph *g = new Graph();
	Node *p = new Node(0);

	printAdjacentMatrix();
	cout << endl;

	for (int i = 0; i < 8; i++) {
		int temp = 0;
		for (int j = 0; j < 8; j++) {
			if (matrix[i][j] == 1) {
				(g->graph + temp)[i] = new Node(j);
				if (temp != 0)
					(g->graph + temp - 1)[i]->next = (g->graph + temp)[i];
				temp++;
			}
		}
	}

	for (int i = 0; i < 8; i++)
		g->visited[i] = false;

	g->dfs(0);
	cout << endl;
}
