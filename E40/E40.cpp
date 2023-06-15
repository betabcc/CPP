#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void listeyazdir(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void ekle(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void sonelemanisil(Node** head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        delete *head;
        *head = NULL;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->prev->next = NULL;
    delete current;
}

int main() {
    Node* head = NULL;
    ekle(&head, 1);
    ekle(&head, 2);
    ekle(&head, 3);
    cout << "ELEMAN SILMEDEN ONCE LISTE: ";
    listeyazdir(head);
    sonelemanisil(&head);
    cout << "ELEMAN SILDIKTEN SONRA LISTE: ";
    listeyazdir(head);
    return 0;
}