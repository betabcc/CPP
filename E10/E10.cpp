#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
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

void sonaNodeEkle(node* l,int veri){
    node* yeniNode=new node;
    yeniNode->data=veri;
    yeniNode->next=NULL;

    node* head=new node;
    head=l;

    while(head->next!=NULL)
        head=head->next;

    head->next=yeniNode;
}

node* basaNodeEkle(node* l, int veri){
    if(l==NULL)
    {
        l=new node;
        l->data=veri;
        return l;
    }
    else
    {
        node* yeniNode=new node;
        yeniNode->data=veri;
        yeniNode->next=l;
        return yeniNode;
    }
}

node* bastanSil(node* l){
    if(l==NULL)
    {
        cout<<"LISTE BOS";
        return NULL;
    }
    else if(l->next==NULL)
    {
        free(l);
        return NULL;
    }
    else
    {
        node* temp=new node;
        temp=l;
        l=l->next;
        free(temp);
        return l;
    }
}

void aradanSirayaGoreDugumSil(node* liste,int sira){
    node* head=liste;
    for(int i=1;i<sira-1;i++)
        head=head->next;
    node* temp=head->next;
    node* head2=temp->next;
    head->next=head2;
    free(temp);
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
    n4->next = NULL;
    for(int i=5; i<11; i++)
        sonaNodeEkle(n1,i*10);
    n1=bastanSil(n1);
    liste(n1);
    cout<<endl;
    aradanSirayaGoreDugumSil(n1,3);
    cout<<endl;
    system("pause");
    return 0;
}