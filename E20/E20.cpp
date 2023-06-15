#include <iostream>
using namespace std;

struct node
{
    node* next;
    int data;
};

node* top=NULL;

void push(int veri){
    node* yeniNode=new node;
    yeniNode->data=veri;
    yeniNode->next=NULL;
    if(top!=NULL)
        yeniNode->next=top;
    top=yeniNode;
}

void pop(){
    if(top==NULL)
        cout<<"STACK BOS";
    else
    {
        node* temp=top;
        top=top->next;
        cout<<temp->data<<" ";
        free(temp);
    }
}

int peek(){
    return top->data;
}

int main()
{
    push(10); push(20); push(30); push(20); pop();
    push(30); pop(); push(40); pop();
    cout<<endl;
    system("pause");
    return 0;
}