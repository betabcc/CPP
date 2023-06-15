#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void listeyazdir(Node* head) {
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

    if (*head != NULL) {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
    } else {
        newNode->next = newNode;
    }
    *head = newNode;
}

Node* listebirlestir(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    Node* last1 = head1;
    while (last1->next != head1) {
        last1 = last1->next;
    }

    Node* last2 = head2;
    while (last2->next != head2) {
        last2 = last2->next;
    }

    last1->next = head2;
    last2->next = head1;

    return (head1->data < head2->data) ? head1 : head2;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    ekle(&head1, 1);
    ekle(&head1, 3);
    ekle(&head1, 5);
    ekle(&head2, 2);
    ekle(&head2, 4);
    ekle(&head2, 6);
    Node* birlestirilenliste = listebirlestir(head1, head2);
    cout << "BIRLESTIRILEN LISTE: ";
    listeyazdir(birlestirilenliste);
    return 0;
}