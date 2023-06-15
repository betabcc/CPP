#include <iostream>
using namespace std;

const int elemanSayisi=10;

struct queue
{
    int front=0;
    int rear=-1;
    int count=0;
    int data[elemanSayisi];
};

bool bosMu(queue* q){
    if (q->count==0)
        return true;
    else
        return false;
}

bool doluMu(queue* q){
    if (q->count==elemanSayisi)
        return true;
    else
        return false;
}

void enqueue(queue* q, int veri){
    if(doluMu(q))
        cout<<"QUEUE DOLU";
    else{
        q->count++;
        q->rear++;
        if(q->rear==elemanSayisi)
            q->rear=0;
        q->data[q->rear]=veri;    
    }
}

int dequeue(queue* q){
    int x=0;
    if (bosMu(q))
        cout<<"QUEUE BOS";
    else{
        x=q->data[q->front];
        q->front++;
        q->count--;
        if (q->front==elemanSayisi)
            q->front=0;
    }
    return x;
}

int main()
{
    queue* kuyruk=new queue;
    for (int i=1; i<4; i++)
        enqueue(kuyruk,i);
    cout<<dequeue(kuyruk);
    cout<<dequeue(kuyruk);
    system("pause");
    return 0;
}