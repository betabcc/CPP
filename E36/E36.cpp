#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
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
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

Node* listebirlestir(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (head1->data < head2->data) {
        head1->next = listebirlestir(head1->next, head2);
        head1->next->prev = head1;
        return head1;
    } else {
        head2->next = listebirlestir(head1, head2->next);
        head2->next->prev = head2;
        return head2;
    }
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
