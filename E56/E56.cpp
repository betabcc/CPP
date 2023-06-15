#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void kuyrukTerseCevir(queue<int>& kuyruk) {
    stack<int> yigin;
    
    while (!kuyruk.empty()) {
        yigin.push(kuyruk.front());
        kuyruk.pop();
    }
    
    while (!yigin.empty()) {
        kuyruk.push(yigin.top());
        yigin.pop();
    }
}

int main() {
    queue<int> kuyruk;
    kuyruk.push(1);
    kuyruk.push(2);
    kuyruk.push(3);
    kuyruk.push(4);
    kuyruk.push(5);
    kuyrukTerseCevir(kuyruk);
    while (!kuyruk.empty()) {
        cout << kuyruk.front() << " ";
        kuyruk.pop();
    }
    return 0;
}