#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Konstanta untuk spasi pada visualisasi tree
#define COUNT 5

struct Node {
    int data;
    Node *left;
    Node *right;
};

void insert(Node **root, int newData){
	if (*root == nullptr){
		Node *newNode;
		newNode = new Node;

		newNode -> data = newData;
		newNode -> left = nullptr;
		newNode -> right = nullptr;

		*root = newNode;

		cout << "Data has been added\n";
	}
	else if (newData < (*root) -> data){
		insert(&((*root)->left), newData);
	}
	else if (newData > (*root) -> data){
		insert(&((*root)->right), newData);
	}
	else if (newData == (*root) -> data){
		cout << "Data is already exist\n";
	}
}

// Fungsi PreOrder Traversal (Root, Left, Right)
void preOrder(Node *root){
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Fungsi InOrder Traversal (Left, Root, Right)
void inOrder(Node *root){
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Fungsi PostOrder Traversal (Left, Right, Root)
void postOrder(Node *root){
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// --- Side Quest Functions ---

// Fungsi rekursif untuk mencetak struktur tree secara visual
void printTreeHelper(Node *root, int space) {
    // Base case
    if (root == nullptr)
        return;

    // Menambah jarak antar level
    space += COUNT;

    // Proses anak kanan terlebih dahulu
    printTreeHelper(root->right, space);

    // Cetak node saat ini setelah spasi
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    // Proses anak kiri
    printTreeHelper(root->left, space);
}

// Fungsi utama untuk mencetak tree
void printTree(Node *root) {
    cout << "Visualisasi Tree (diputar 90 derajat):\n";
    cout << "==========================================\n";
    if (root == nullptr) {
        cout << "Tree is empty!\n";
        return;
    }
    // Memulai dengan spasi awal 0
    printTreeHelper(root, 0);
};

// --- Main Function ---

int main(){
    int opt, val;
    Node *tree;
    tree = NULL;

    do {
    	system("cls");

    cout << "===== BINARY SEARCH TREE =====\n";
	cout << "1. Insert\n";
	cout << "2. PreOrder Traversal\n";
	cout << "3. InOrder Traversal\n";
	cout << "4. PostOrder Traversal\n";
	cout << "5. Print Tree Structure\n"; // Opsi tambahan
	cout << "6. Exit\n"; // Exit diubah menjadi 6
	
	cout << "\nOption: "; cin >> opt;

	switch (opt) {

		case 1:
			cout << "\n Input:";
			cout << "\n ------";
			cout << "\n New data: ";
			cin >> val;
			insert(&tree, val);
			break;

		case 2:
			cout << "\nPreOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				preOrder(tree);
                cout << endl;
			}
			break;

		case 3:
			cout << "\nInOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				inOrder(tree);
                cout << endl;
			}
			break;

		case 4:
			cout << "\nPostOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				postOrder(tree);
                cout << endl;
			}
			break;
        
        case 5:
            cout << endl;
            printTree(tree);
            break;

		case 6:
			return 0;
			
		default:
			cout << "Option is not valid! Please re-enter your option";
			break;
	}
	
    cout << "\n\nPress any key to continue...";
	getch();
    } while(opt != 6); // Kondisi loop diubah
    return 0;
}