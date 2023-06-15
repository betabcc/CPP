#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* yeniNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void cbdl(Node* root, Node** head) {
    if (root == NULL) return;
    static Node* prev = NULL;
    cbdl(root->left, head);
    if (prev == NULL)
        *head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    cbdl(root->right, head);
}

Node* cbdl(Node* root) {
    Node* head = NULL;
    cbdl(root, &head);
    return head;
}

void yazdir(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->right;
    }
}

int main() {
    Node* root = yeniNode(8);
    root->left = yeniNode(3);
    root->right = yeniNode(10);
    root->left->left = yeniNode(1);
    root->left->right = yeniNode(6);
    root->right->right = yeniNode(14);
    root->left->right->left = yeniNode(4);
    root->left->right->right = yeniNode(7);
    root->right->right->left = yeniNode(13);
    Node* head = cbdl(root);
    yazdir(head);
    return 0;
}