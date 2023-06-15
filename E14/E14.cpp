#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

node* dugumEkle(node* liste, int veri){
    if(liste==NULL)
    {
        liste=new node;
        liste->data=veri;
        liste->next=NULL;
        liste->prev=NULL;
    }
    else
    {
        node* head=liste;
        while(head->next!=NULL)
            head=head->next;
        node* yeniDugum=new node;
        yeniDugum->data=veri;
        yeniDugum->next=NULL;
        yeniDugum->prev=head;
        head->next=yeniDugum;
    }
    return liste;
}

void yazdir(node* liste){
    node* head=liste;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void arayaNodeEkle(node* liste,int data,int sira){
    node* h1=liste;
    for(int i=1;i<sira-1;i++)
        h1=h1->next;
    node* h2=h1->next;
    node* yeniNode=new node;
    yeniNode->data=data;
    yeniNode->next=h2;
    yeniNode->prev=h1;
    h1->next=yeniNode;
    h2->prev=yeniNode;
}

int main()
{
    node* l=NULL;
    for (int i = 1; i < 11; i++)
        l=dugumEkle(l,5*i);
    cout<<endl;
    arayaNodeEkle(l,100,5);
    yazdir(l);
    system("pause");
    return 0;
}