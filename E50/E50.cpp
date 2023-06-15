#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void ekle(int x) {
    Node* temp = new Node();
    temp->data = x;
    if (head == NULL) {
        head = temp;
        temp->next = head;
        temp->prev = head;
    } else {
        Node* temp1 = head;
        while (temp1->next != head) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
        temp->next = head;
        head->prev = temp;
    }
}

void ilkindissil(int index) {
    if (head == NULL) {
        return;
    }
    if (index == 0) {
        Node* temp2 = head;
        head = head->next;
        head->prev = temp2->prev;
        temp2->prev->next = head;
        delete temp2;
        return;
    }
    Node* temp1 = head;
    for (int i = 0; i < index - 1; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next->prev = temp1;
    delete temp2;
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
    cout << "ILK INDISTEKI ELEMANI SILMEDEN ONCE: ";
    listeyazdir();
    ilkindissil(2);
    cout << "ILK INDISTEKI ELEMANI SILDIKTEN SONRA: ";
    listeyazdir();
    return 0;
}