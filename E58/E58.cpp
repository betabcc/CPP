#include <iostream>
using namespace std;

const int maxBoyut = 100;

class Queue {
private:
    int front, rear;
    int items[maxBoyut];
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    
    bool doluMu() {
        return (front == 0 && rear == maxBoyut - 1) || (front == rear + 1);
    }
    
    bool bosMu() {
        return front == -1;
    }
    
    void basaEkle(int x) {
        if (doluMu()) {
            cout << "KUYRUK DOLU!\n";
            return;
        }
        
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = maxBoyut - 1;
        else
            front--;
        
        items[front] = x;
        cout << x << " BASA EKLENDI.\n";
    }
    
    void sonaEkle(int x) {
        if (doluMu()) {
            cout << "KUYRUK DOLU!\n";
            return;
        }
        
        if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == maxBoyut - 1)
            rear = 0;
        else
            rear++;
        
        items[rear] = x;
        cout << x << " SONA EKLENDI.\n";
    }
    
    void bastanCikar() {
        if (bosMu()) {
            cout << "KUYRUK BOS!\n";
            return;
        }
        
        cout << items[front] << " BASTAN CIKARILDI.\n";
        
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == maxBoyut - 1)
            front = 0;
        else
            front++;
    }
    
    void sondanCikar() {
        if (bosMu()) {
            cout << "KUYRUK BOS!\n";
            return;
        }
        
        cout << items[rear] << " SONDAN CIKARILDI.\n";
        
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = maxBoyut - 1;
        else
            rear--;
    }
};

int main() {
    Queue q;
    q.basaEkle(10);
    q.basaEkle(20);
    q.sonaEkle(30);
    q.sonaEkle(40);
    q.bastanCikar();
    q.sondanCikar();
    return 0;
}