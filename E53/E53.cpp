#include <iostream>
#include <list>

class TekBagliDogrusalListe {
public:
    void geriit(int data) {
        Node* yeniNode = new Node(data);
        if (head == nullptr) {
            head = yeniNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = yeniNode;
        }
    }

    int al(int index) {
        if (head == nullptr || index < 0) {
            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            if (current->next == nullptr) {
                return -1;
            }
            current = current->next;
        }
        return current->data;
    }

private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };
    Node* head = nullptr;
};

void indeksYazdir(TekBagliDogrusalListe& L, std::list<int>& P) {
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
    TekBagliDogrusalListe L;
    L.geriit(123);
    L.geriit(298);
    L.geriit(3);
    L.geriit(4);
    L.geriit(512);
    L.geriit(6);
    L.geriit(767);
    std::list<int> P = {1, 2, 5, 7};
    indeksYazdir(L, P);
    return 0;
}