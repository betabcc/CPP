#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct queue
{
    int count=0;
    node* front;
    node* rear;
};

bool bosMu(queue* q)
{
    if(q->count==0)
        return true;
    return false;
}

void enqueue(queue* q, int veri)
{
    node* yeni=new node;
    yeni->data=veri;
    yeni->next=NULL;

    if (bosMu(q))
    {
        q->front=yeni;
        q->rear=yeni;
    }
    else
    {
        q->rear->next=yeni;
        q->rear=yeni;
    }
    q->count++;
}

int dequeue(queue* q)
{
    int x=0;
    if (!bosMu(q))
    {
        x=q->front->data;
        node* temp=q->front;
        q->front=q->front->next;
        q->count--;
        free(temp);
    }
    return x;
}

int main()
{
    queue* kuyruk = new queue;
    kuyruk->count=0;
    kuyruk->front=NULL;
    kuyruk->rear=NULL;
    enqueue(kuyruk,10); enqueue(kuyruk,20); enqueue(kuyruk,30);
    enqueue(kuyruk,14); enqueue(kuyruk,15); enqueue(kuyruk,16);
    int a=0;
    for(int i=0; i<9; i+=2)
        a += dequeue(kuyruk);
    cout << a;
    system("pause");
    return 0;
}