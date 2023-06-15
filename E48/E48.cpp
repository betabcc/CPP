#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void ekle(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void ilkindissil(int index) {
    if (head == NULL) {
        return;
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current->next == NULL) {
            return;
        }
        current = current->next;
    }
    if (current->next == NULL) {
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = current;
    }
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
    cout << "ILK INDISTEKI ELEMANI SILMEDEN ONCE: ";
    listeyazdir();
    ilkindissil(2);
    cout << "ILK INDISTEKI ELEMANI SILDIKTEN SONRA: ";
    listeyazdir();
    return 0;
}