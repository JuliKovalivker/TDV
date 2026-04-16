#include <iostream>
#include <list>
#include<queue>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

//Aca pueden decidir si devolver la lista o directamente ir haciendo prints de los nodos
void printRightView(Node* root)
{
	queue<Node*> q;
	q.push(root);
	Node* curr = nullptr;
	while (!q.empty()){
		int size = q.size();
		int i = 0;
		while(i++ < size){
			curr = q.front();
			q.pop();
			if (i == size) cout << curr->key << endl;
			if (curr->left) q.push(curr->left);
			if (curr->right) q.push(curr->right);
		}
	}
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	printRightView(root);

	return 0;
}