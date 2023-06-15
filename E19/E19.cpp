#include <iostream>
using namespace std;

const int elemanSayisi=5;

struct node
{
    int dizi[elemanSayisi];
    int top=-1;
};

void push(node* s, int veri) {
    if(s->top==elemanSayisi-1)
        cout<<"STACK DOLU";
    else
    {
        s->top+=1;
        s->dizi[s->top]=veri;
    }
}

void pop(node* s){
    if(s->top==-1)
        cout<<"STACK BOS";
    else
    {
        cout<<s->dizi[s->top]<<" ";
        s->dizi[s->top]=NULL;
        s->top-=1;

    }
}

void yazdir(node* s){
    for(int i=s->top; i>=0; i--)
        cout<<s->dizi[i]<<" ";
}

void reset(node* s){
    s->top=-1;
}

int numberOfNotes(node* s){
    int n=0;
    n=s->top+1;
    return n;
}

int peek(node* s){
    return s->dizi[s->top];
}

int main()
{
    node* stack1=new node;
    push(stack1,10); pop(stack1); push(stack1,20); push(stack1,30); pop(stack1);
    push(stack1,10); push(stack1,20); pop(stack1);
    yazdir(stack1);
    cout<<endl;
    system("pause");
    return 0;
}