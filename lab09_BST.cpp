/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : lab09
* Description: BST
* Algorithm :
**********************************************************/
#include<iostream>
#include<string>
using namespace std;
class Node {
public:
	int data;
	Node* right;
	Node* left;

	Node(int data) {
		this->data = data;
		right = NULL;
		left = NULL;
	}

};
class BST {
public:
	Node* root;
	BST() {
		root = NULL;
	}
	Node* search(Node* p,int key) {
		if (p == NULL)
			return NULL;
		if (key == p->data)
			return p;
		else if (key < p->data)
			return search(p->left, key);
		else if (key > p->data)
			return search(p->right, key);
		
	}
	Node* insert(Node* ptr,int data) {
		if(root==NULL)
			root = new Node(data);
		if (ptr == NULL) 
			ptr = new Node(data);
		else if (data < ptr->data)
			ptr->left=insert(ptr->left, data);
		else if (data > ptr->data)
			ptr->right=insert(ptr->right, data);
		return ptr;
	}
	Node* Delete(Node* ptr, int key){
		if (ptr != NULL) {
			if (key < ptr->data)
				ptr->left = Delete(ptr->left, key);
			else if (key>ptr->data)
				ptr->right = Delete(ptr->right, key);
			else if ((ptr->left == NULL) && (ptr->right == NULL)) {
				ptr = NULL;

			}
			else if (ptr->left == NULL){
				Node* p = ptr;
				ptr = ptr->right; 
				delete p;
			}
			else if (ptr->right == NULL) {
				Node* p = ptr;
				ptr = ptr->left;
				delete p;
			}
			else
				ptr->data = find_min(ptr->left);
		}
		else
			cout << "Not Found" << endl;
		return ptr;
	}
	
	int find_min(Node* ptr) {
		int temp;
		if (ptr->left == NULL) {
			temp = ptr->data;
			ptr = ptr->right;
		}
		else
			temp = find_min(ptr->left);
		return temp;
	}
	void print(Node* temp) {
		if (temp) {
			print(temp->left);
			cout << temp->data<<" ";
			print(temp->right);
		}
	}
};


void main() {
	BST* bst=new BST();
	int data;
	int select=0;
	while (select != 5) {
		cout << "1.insert 2.delete 3.search 4.print" << endl;
		cin >> select;
		switch (select) {
		case 1:
			cin >> data;
			bst->insert(bst->root, data);
			break;
		case 2:
			cin >> data;
			bst->Delete(bst->root, data);
			break;
		case 3:
			cin >> data;
			if (bst->search(bst->root, data))
				cout << "Found" << endl;
			else
				cout << "Not Found" << endl;
			break;
		case 4:
			bst->print(bst->root);
			cout << endl;
			break;
		}

	}

}
