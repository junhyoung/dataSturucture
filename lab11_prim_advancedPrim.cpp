/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : Lab11
* Description: Prim, Advanced Prim
* Algorithm : prim - 각 방문점에서 코스트가 가장 짧은 노드로 이동
			  Advanced Prim - 방문한 모든점에서 코스트가 짧은 노드를 검색하여 이동
**********************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int matrix[6][6] = {
	{0,5,100,12,100,100},
	{5,0,6,10,24,100},
	{100,6,0,17,100,30},
	{12,10,17,0,20,100},
	{100,24,100,20,0,13},
	{100,100,30,100,13,0}
};
bool visited[6];
char change(int vertax) {
	return 'A' + vertax;
}
int prim(int vertax) {
	visited[vertax] = true;
	int minCost=999;
	int minVertax=999;
	for (int i = 0; i < 6; i++) {
		if (!visited[i] && minCost>matrix[vertax][i]) {
			minCost = matrix[vertax][i];
			minVertax = i;
		}
	}
	int count = 0;
	for (int i = 0; i < 6; i++) {
		if (visited[i])
			count++;
	}
	if (count == 6)
		return 0;
	else {
		cout << "(" << change(vertax) << "," << change(minVertax) << ")" << " ";
		return minCost + prim(minVertax);
	}
}
int start;
int advancedPrim(int vertax) {
	visited[vertax] = true;
	int minCost = 999;
	int minVertax = 999;
	for (int i = 0; i < 6; i++) {
		if (visited[i]) {
			for (int j = 0; j<6; j++) {
				if (!visited[j] && minCost>matrix[i][j]) {
					minCost = matrix[i][j];
					minVertax = j;
					vertax = i;
				}
			}
		}
	}
		int count = 0;
		for (int i = 0; i < 6; i++) {
			if (visited[i])
				count++;
		}
		if (count == 6)
			return 0;
		else {
			cout << "(" << change(vertax) << "," << change(minVertax) << ")" << " ";
			return minCost + advancedPrim(minVertax);
		}
}
void main() {
	cout << "  ";
	for (int i = 0; i < 6; i++) {
		visited[i] = false;
		cout << change(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << change(i)<<" ";
		for (int j = 0; j < 6; j++) {
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl << "Prime Weight : " << prim(0) << endl;
	for (int i = 0; i < 6; i++) {
		visited[i] = false;
	}
	start = 0;
	cout << endl << "Advanced Prime Weight : " << advancedPrim(0) << endl;
}

