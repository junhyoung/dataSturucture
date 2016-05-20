/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : lab09
* Description: Heap
* Algorithm :
**********************************************************/
#include<iostream>
#include<string>
#define maxSize 200
#define heapFull(n) n==maxSize
#define heapEmpty(n) !n
using namespace std;

class Heap {
public:
	int key;
	int* H;

	Heap() {
		key = 0;
		H = new int[maxSize];
	}
	void insert_maxheap(int data) {
		int I;
		if (heapFull(key))
			cout << "Heap is Full" << endl;
		else {
			I = ++key;
			while ((I != 1) && (data > H[I / 2])) {
				H[I] = H[I / 2];
				I = I / 2;
			}
			H[I] = data;
		}
	}
	int delete_maxheap() {
		int parent, child;
		int item, temp;
		item = H[1]; temp = H[key--];
		parent = 1;
		child = 2;
		while (child <= key) {
			if (child < key && (H[child] < H[child + 1]))
				child++;
			if (temp >= H[child]) break;
			H[parent] = H[child];
			parent = child;
			child = child * 2;
		}
		H[parent] = temp;
		return item;
	}

};


void main() {
	int n = 0;

}
