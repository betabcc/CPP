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

int elemanSayisi(node* liste){
    int sayac=0;
    node* head=liste;
    while(head!=NULL)
    {
        sayac++;
        head=head->next;
    }
    return sayac;
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
    cout<<"ELEMAN SAYISI: "<<elemanSayisi(n1);
    cout<<endl;
    system("pause");
    return 0;
}