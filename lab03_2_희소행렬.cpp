/********************************
이름		: 최 준 형
학번		: 20123425
ID			: Lab03-2
Description :희소행렬
Algoritm	:
varialbes	:
*********************************/
#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream instream("lab03-2.dat");
	int arr[100][100] = { 0 };
	int Sparse[100][3] = { 0 };
	int Transe[100][3] = { 0 };
	int num = 0;
	int index = 1;
	instream >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			instream >> arr[i][j];
			if (arr[i][j]!=0) {
				Sparse[index][0] = i;
				Sparse[index][1] = j;
				Sparse[index][2] = arr[i][j];
				index++;
			}
		}
	}
	cout << "Matrix" << endl;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	Sparse[0][0] = Transe[0][0] = num;
	Sparse[0][1] = Transe[0][1] = num;
	Sparse[0][2] = Transe[0][2] = index - 1;

	cout << "Matrix A" << endl;
	for (int i = 0; i < index; i++) {
		cout << Sparse[i][0] << " " << Sparse[i][1] << " " << Sparse[i][2] << " " << endl;
	}
	cout << endl;

	int value = 1;
	for (int i = 0; i < num; i++) {
		for (int j = 1; j < index; j++) {
			if (Sparse[j][1] == i) {
				Transe[value][0] = Sparse[j][1];
				Transe[value][1] = Sparse[j][0];
				Transe[value][2] = Sparse[j][2];
				value++;
			}
		}
	}
	cout << "Matrix B" << endl;
	for (int i = 0; i < index; i++) {
		cout << Transe[i][0] << " " << Transe[i][1] << " "<<Transe[i][2] << " "<<endl;
		//cout << Sparse[i][0] << " " << Sparse[i][1] << " "<< Sparse[i][2] << " "<<endl;
	}
	return 0;
}
