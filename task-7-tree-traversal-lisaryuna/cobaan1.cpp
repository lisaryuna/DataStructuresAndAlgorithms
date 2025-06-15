#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

// --- FUNGSI-FUNGSI STANDAR (TIDAK BERUBAH) ---

void insert(Node **root, int newData){
	if (*root == NULL){
		Node *newNode;
		newNode = new Node;
		newNode -> data = newData;
		newNode -> left = NULL;
		newNode -> right = NULL;
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

void preOrder(Node *root){
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root){
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node *root){
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

// --- FUNGSI UNTUK MENCETAK TREE ---

int getTreeHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
}

void fillPrintMatrix(Node* root, vector<string>& matrix, int level, int left, int right) {
    if (root == NULL) {
        return;
    }

    int mid = (left + right) / 2;
    
    ostringstream oss;
    oss << root->data;
    string val_str = oss.str();
    int val_len = val_str.length();

    int start_pos = mid - (val_len / 2);
    if (start_pos < 0) start_pos = 0;

    matrix[level * 2].replace(start_pos, val_len, val_str);

    if (root->left) {
        int child_mid = (left + mid - 1) / 2;
        matrix[level * 2 + 1][child_mid + 1] = '/';
        fillPrintMatrix(root->left, matrix, level + 1, left, mid - 1);
    }

    if (root->right) {
        int child_mid = (mid + 1 + right) / 2;
        // Perbaikan: Karakter backslash harus ditulis '\\' agar valid
        matrix[level * 2 + 1][child_mid] = '\\'; 
        fillPrintMatrix(root->right, matrix, level + 1, mid + 1, right);
    }
}

void printTree(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return;
    }

    int height = getTreeHeight(root);
    
    // ==========================================================
    // PERBAIKAN JARAK/SPASI ADA DI SINI
    // ==========================================================
    // Rumus lebar diubah agar lebih rapat. Angka '5' bisa diubah untuk penyesuaian.
    int width = 5 * pow(2, height - 1);
    // ==========================================================

    vector<string> matrix(height * 2, string(width, ' '));

    fillPrintMatrix(root, matrix, 0, 0, width - 1);

    for (int i = 0; i < height * 2; ++i) {
        size_t last = matrix[i].find_last_not_of(' ');
        if (string::npos != last) {
            cout << matrix[i].substr(0, last + 1) << endl;
        }
    }
}

// --- FUNGSI MAIN (TIDAK BERUBAH) ---

int main() {
    int opt, val;
    Node *tree = NULL;

    do {
    	system("cls");

        cout << "===== BINARY SEARCH TREE =====\n";
        cout << "1. Insert\n";
        cout << "2. PreOrder Traversal\n";
        cout << "3. InOrder Traversal\n";
        cout << "4. PostOrder Traversal\n";
        cout << "5. Print Tree Structure\n";
        cout << "6. Exit\n";
        
        cout << "\nOption: "; cin >> opt;

        switch (opt) {
            case 1:
                cout << "\n Input:\n ------\n New data: ";
                cin >> val;
                insert(&tree, val);
                break;
            case 2:
                cout << "\nPreOrder Traversal\n==========================\n";
                if (tree == NULL) cout << "Tree is empty!\n";
                else { preOrder(tree); cout << endl; }
                break;
            case 3:
                cout << "\nInOrder Traversal\n==========================\n";
                if (tree == NULL) cout << "Tree is empty!\n";
                else { inOrder(tree); cout << endl; }
                break;
            case 4:
                cout << "\nPostOrder Traversal\n==========================\n";
                if (tree == NULL) cout << "Tree is empty!\n";
                else { postOrder(tree); cout << endl; }
                break;
            case 5:
                cout << "\nStruktur Tree:\n==========================\n";
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
    } while (opt != 6);

    return 0;
}