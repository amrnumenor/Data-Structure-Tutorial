#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class BST {
    private:
    node* root;
    //
    // Insert node into the binary search tree
    //
    node* insert(int x, node* t) {
        if(t == NULL) {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data) t->left = insert(x, t->left);
        else if(x > t->data) t->right = insert(x, t->right);
        return t;
    }
    //
    // Binary search tree preorder traversal 
    //
    void preorder(node* t) {
        if(t == NULL) return;
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
    //
    // Binary search tree preorder traversal 
    //
    void inorder(node* t) {
        if(t == NULL) return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
    //
    // Binary search tree preorder traversal 
    //
    void postorder(node*t) {
        if(t == NULL) return;
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }
    // 
    // Find the specific node in a binary search tree
    //
    node* find(int x, node* t) {
        if(t == NULL) return NULL;
        else if(x < t->data) return find(x, t->left);
        else if(x > t->data) return find(x, t->right);
        else return t;
    }
    //
    // Find the node that hold the smallest value in the binary search tree
    //
    node* findMin(node* t) {
        if(t == NULL) return NULL;
        else if(t->left == NULL) return t;
        else findMin(t->left);
    }
    //
    // Delete the desired node from the binary search tree
    //
    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL) return NULL;
        else if(x < t->data) t->left = remove(x, t->left);
        else if(x > t->data) t->right = remove(x, t->right);
        else {
            temp = t;
            if(t->left == NULL) {
                t = t->right;
                delete temp;
                return t;
            }
            else if(t->right == NULL) {
                t = t->left;
                delete temp;
                return t;
            }
        }
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
        return t;
    }
    public:
    BST() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void inorder() {
        inorder(root);
    }

    void preorder() {
        preorder(root);
    }

    void postorder() {
        postorder(root);
    }

    void search(int x) {
        node* n = find(x, root);
        if(n == NULL) cout << x << "is not found!" << endl;
        else cout << x << " is found!" << endl;
    }

    void remove(int x) {
        root = remove(x, root);
    }
};

int main() {
    BST tr;
    tr.insert(6);tr.insert(2);tr.insert(8);
    tr.insert(1);tr.insert(4);tr.insert(3);
    // tr.inorder();
    // cout << endl;    
    tr.preorder();
    cout << endl;
    // tr.postorder();
    // cout << endl;
    tr.search(4);
    return 0;
}