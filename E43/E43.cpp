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
    temp->next = head;
    head = temp;
}

void ilksil() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void listeyazdir() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
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