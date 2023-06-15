#include <iostream>
#include <list>

class CiftBagliDaireselListe {
public:
    void geriit(int data) {
        Node* yeniNode = new Node(data);
        if (head == nullptr) {
            head = yeniNode;
            head->next = head;
            head->prev = head;
        } else {
            yeniNode->next = head;
            yeniNode->prev = head->prev;
            head->prev->next = yeniNode;
            head->prev = yeniNode;
        }
    }

    int al(int index) {
        if (head == nullptr || index < 0) {
            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
            if (current == head) {
                return -1;
            }
        }
        return current->data;
    }

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    };
    Node* head = nullptr;
};

void indeksYazdir(CiftBagliDaireselListe& L, std::list<int>& P) {
    for (const int& index : P) {
        int deger = L.al(index - 1);
        if (deger != -1) {
            std::cout << "L[" << index << "] = " << deger << std::endl;
        } else {
            std::cout << "L[" << index << "] ALAN DIŞINDA" << std::endl;
        }
    }
}

int main() {
    CiftBagliDaireselListe L;
    L.geriit(99);
    L.geriit(2);
    L.geriit(34);
    L.geriit(47);
    L.geriit(5);
    L.geriit(69);
    L.geriit(7);
    std::list<int> P = {1, 3, 4, 6};
    indeksYazdir(L, P);
    return 0;
}