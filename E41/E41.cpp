#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void listeyazdir(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head->next;
    cout << head->data << " ";
    while (current != head) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void ekle(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = newNode;
}

void sonelemanisil(Node** head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == *head) {
        delete *head;
        *head = NULL;
        return;
    }
    Node* current = *head;
    while (current->next->next != *head) {
        current = current->next;
    }
    Node* last = current->next;
    current->next = *head;
    delete last;
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