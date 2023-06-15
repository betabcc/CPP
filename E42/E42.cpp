#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void listeyazdir(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void ekle(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    (*head)->prev = newNode;
    Node* current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
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
    (*head)->prev = current;
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