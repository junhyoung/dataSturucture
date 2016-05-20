/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : lab08
* Description: Binary Tree 
* Algorithm : 
**********************************************************/
#include<iostream>
#include<string>

using namespace std;
class Node {
public:
	char data;
	int prio;
	Node* right;
	Node* left;
	Node(char data) {
		this->data = data;
		right = NULL;
		left = NULL;
		prio = 4;
	}
};

class Tree {
public:
	Node* root;
	Tree() {
		root = NULL;
	}
	void Operand(Node* temp) {
		if (root) {
			Node*p = root;
			while (p->right != NULL)
				p = p->right;
			p->right = temp;
		}
		else {
			root = temp;
		}
	}
	void Operator(Node* temp) {
		if (root->prio >= temp->prio) {
			temp->left = root;
			root = temp;
		}
		else {
			temp->left = root->right;
			root->right = temp;
		}
	}
	int Evaluation(Node* temp) {
		int left, right;
		int result;
		if (temp != NULL) {
			if (temp->data - '0' < 10 && temp->data - '0' >= 0)
				result = temp->data - '0';
			else {
				left = Evaluation(temp->left);
				right = Evaluation(temp->right);
				switch (temp->data) {
				case '+': result = left + right; break;
				case '-': result = left - right; break;
				case '*': result = left * right; break;
				case '/': result = left / right; break;
				}
			}
		}
		else
			result = 0;
		return result;
	}
	void inorder(Node* temp) {
		if (temp) {
			inorder(temp->left);
			cout << temp->data;
			inorder(temp->right);
		}
	}
	void postorder(Node* temp) {
		if (temp) {
			postorder(temp->left);
			postorder(temp->right);
			cout << temp->data;
		}

	}
	void preorder(Node* temp) {
		if (temp) {
			cout << temp->data;
			preorder(temp->left);
			preorder(temp->right);
		}

	}
	
};

void main() {
	string power;
	cin >> power;
	int i, j;
	Node* temp;
	char prec[5][2] = { '^',3,'*',2,'/',2,'+',1,'-',1 };
	Tree* tree = new Tree();
	for (i = 0; power[i]; i++) {
		temp = new Node(power[i]);
		for (j = 0; j <= 4; j++) {
			if (temp->data == prec[j][0]){
				temp->prio = prec[j][1];
				break;
			}
		}
		if (j == 5)
			tree->Operand(temp);
		else
			tree->Operator(temp);
	}
	cout << "input : " << power << endl;
	cout << " output : inorder : " ;
	tree->inorder(tree->root);
	cout << " ";
	cout << " postorder : ";
	tree->postorder(tree->root);
	cout << " ";
	cout << "preorder : ";
	tree->preorder(tree->root);
	cout << endl;
	cout <<"Evaluation : "<< tree->Evaluation(tree->root) << endl;
	
}
