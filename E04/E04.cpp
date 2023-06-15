#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next = NULL;
};

void liste(node* l)
{
    node* head=new node;
    head=l;
    while(head!=NULL)
    {
      cout << head->data << " ";
      head = head->next;
    }
}

int main()
{
    node* n1 = new node;
    node* n2 = new node;
    node* n3 = new node;
    node* n4 = new node;
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;
    n4->data = 40;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    liste(n1);
    system ("pause");
    return 0;
}