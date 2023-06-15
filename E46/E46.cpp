#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void ekle(int x) {
    Node* temp = new Node();
    temp->data = x;
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp->next = head;
        temp->prev = tail;
    } else {
        tail->next = temp;
        temp->prev = tail;
        head->prev = temp;
        temp->next = head;
        tail = temp;
    }
}

void ilksil() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
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