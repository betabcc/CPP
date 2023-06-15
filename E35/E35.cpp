#include <iostream>
using namespace std;

struct Node {
    int data;
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
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
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
        return head1;
    } else {
        head2->next = listebirlestir(head1, head2->next);
        return head2;
    }
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    int n1;
    cout << "ILK LISTE ICIN KAC TANE SAYI OLSUN: ";
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int data;
        cout << "Sayi girin: ";
        cin >> data;
        ekle(&head1, data);
    }

    int n2;
    cout << "IKINCI LISTE ICIN KAC TANE SAYI OLSUN: ";
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int data;
        cout << "Sayi girin: ";
        cin >> data;
        ekle(&head2, data);
    }

    Node* mergedList = listebirlestir(head1, head2);

    cout << "BIRLESTIRILMIS LISTE: ";
    listeyazdir(mergedList);
    return 0;
}