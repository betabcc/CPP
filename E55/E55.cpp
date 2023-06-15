#include <iostream>
#include <stack>

using namespace std;

void asal_carpanlar(int n, stack<int>& yigin) {
    int i = 2;
    while (n > 1) {
        while (n % i == 0) {
            yigin.push(i);
            n /= i;
        }
        i++;
    }
}

void yigin_yazdir(stack<int>& yigin) {
    while (!yigin.empty()) {
        cout << yigin.top() << " ";
        yigin.pop();
    }
}

int main() {
    int n;
    cout << "BIR POZITIF TAM SAYI GIRIN: ";
    cin >> n;
    stack<int> yigin;
    asal_carpanlar(n, yigin);
    cout << n << " SAYISININ ASAL CARPANLARI: ";
    yigin_yazdir(yigin);
    cout << endl;
    return 0;
}