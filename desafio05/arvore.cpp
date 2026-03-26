#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n) {
    if (n == nullptr)
        return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

// rotação à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// rotação à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* n) {
    if (n == nullptr)
        return 0;
    return height(n->left) - height(n->right);
}

Node* insert(Node* node, int key) {

    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);

    else if (key > node->key)
        node->right = insert(node->right, key);

    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Caso esquerda-esquerda
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Caso direita-direita
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Caso esquerda-direita
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso direita-esquerda
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == nullptr)
        return;

    space += indent;

    printTree(root->right, space);

    cout << endl;
    for (int i = indent; i < space; i++)
        cout << " ";

    cout << root->key << "\n";

    printTree(root->left, space);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Arvore AVL balanceada:\n";
    printTree(root);

    return 0;
}
