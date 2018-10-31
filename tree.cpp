#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

node* createNode(int value){
	struct node* newNode = new node;
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

void insertLeft(node *root, int value){
	root->left = createNode(value);
}

void insertRight(node* root, int value){
	root->right = createNode(value);
}

void inorder(node* root){
	if(root==NULL) return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void preorder(node* root){
	if(root==NULL) return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root){
	if(root==NULL) return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	node* root = createNode(1);
	insertLeft(root,12);
	insertRight(root,9);

	insertLeft(root->left,5);
	insertRight(root->left,6);

	cout<<"Inorder Traversal\n";
	inorder(root);
	cout<<"\nPreorder Traversal\n";
	preorder(root);
	cout<<"\nPostorder Traversal\n";
	postorder(root);
	cout<<endl;
	return 0;
}