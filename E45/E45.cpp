#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void ekle(int x) {
    Node* temp = new Node();
    temp->data = x;
    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
        head = temp;
    }
}

void ilksil() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    Node* curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = head->next;
    head = head->next;
    delete temp;
}

void listeyazdir() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    ekle(5);
    ekle(10);
    ekle(15);
    ekle(20);
    ekle(25);
    cout << "ELEMAN SILMEDEN ONCE LISTE: ";
    listeyazdir();
    ilksil();
    cout << "ELEMAN SILDIKTEN SONRA LISTE: ";
    listeyazdir();
    return 0;
}