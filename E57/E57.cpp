#include <iostream>
#include <stack>

using namespace std;

void kuleYazdir(stack<int> A, stack<int> B, stack<int> C) {
    cout << "A:";
    while (!A.empty()) {
        cout << " " << A.top();
        A.pop();
    }
    cout << endl;
    
    cout << "B:";
    while (!B.empty()) {
        cout << " " << B.top();
        B.pop();
    }
    cout << endl;
    
    cout << "C:";
    while (!C.empty()) {
        cout << " " << C.top();
        C.pop();
    }
    cout << endl;
}

void hanoi(int n, stack<int>& kaynak, stack<int>& hedef, stack<int>& destek) {
    if (n > 0) {
        hanoi(n - 1, kaynak, destek, hedef);
        
        hedef.push(kaynak.top());
        kaynak.pop();
        
        kuleYazdir(kaynak, destek, hedef);
        
        hanoi(n - 1, destek, hedef, kaynak);
    }
}

int main() {
    int n;
    stack<int> A, B, C;
    cout << "DISK SAYISINI GIRINIZ: ";
    cin >> n;
    for (int i = n; i >= 1; i--) {
        A.push(i);
    }
    cout << "BASLANGIC DURUMU:" << endl;
    kuleYazdir(A, B, C);
    hanoi(n, A, C, B);
    return 0;
}