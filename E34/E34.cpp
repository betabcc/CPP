#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void liste(Node** head, int n, int range) {
    srand(time(NULL));
    *head = new Node();
    (*head)->data = rand() % range;
    (*head)->next = *head;
    (*head)->prev = *head;
    Node* current = *head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node();
        newNode->data = rand() % range;
        newNode->next = *head;
        newNode->prev = current;
        current->next = newNode;
        (*head)->prev = newNode;
        current = current->next;
    }
}

void listeyazdir(Node* head) {
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, range;
    cout << "KAC TANE SAYI OLSUN: ";
    cin >> n;
    cout << "SAYILAR EN FAZLA KACA KADAR OLABILIR: ";
    cin >> range;
    liste(&head, n, range);
    cout << "SONUC: ";
    listeyazdir(head);
    return 0;
}