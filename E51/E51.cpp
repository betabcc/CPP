#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class Palindrome {
private:
    Node* head;
    Node* tail;

public:
    Palindrome() {
        head = NULL;
        tail = NULL;
    }

    void add(char c) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->prev = tail;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    bool palindromMu() {
        Node* front = head;
        Node* back = tail;

        while (front != back && front->prev != back) {
            if (front->data != back->data) {
                return false;
            }
            front = front->next;
            back = back->prev;
        }

        return true;
    }
};

int main() {
    string word;
    cout << "KELİME GİRİN: ";
    cin >> word;
    Palindrome p;
    for (int i = 0; i < word.length(); i++) {
        p.add(word[i]);
    }
    if (p.palindromMu()) {
        cout << word << " PALINDROM KELIMEDIR." << endl;
    } else {
        cout << word << " PALINDROM KELIME DEGILDIR." << endl;
    }
    return 0;
}