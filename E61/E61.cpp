#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void kabarcik(Node** start) {
    bool degistir;
    Node** ptr;
    
    if (*start == NULL)
        return;
    
    do {
        degistir = false;
        ptr = start;
        
        while ((*ptr)->next != NULL) {
            if ((*ptr)->data > (*ptr)->next->data) {
                Node* temp = *ptr;
                *ptr = (*ptr)->next;
                temp->next = (*ptr)->next;
                (*ptr)->next = temp;
                degistir = true;
            }
            ptr = &(*ptr)->next;
        }
    } while (degistir);
}

void yazdir(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* start = NULL;
    push(&start, 78);
    push(&start, 45);
    push(&start, 38);
    push(&start, 12);
    push(&start, 59);
    cout << "SIRALAMADAN ONCE: ";
    yazdir(start);
    kabarcik(&start);
    cout << "\nSIRALAMADAN SONRA: ";
    yazdir(start);
    return 0;
}