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

void aradanAdreseGoreSil(node* liste, node* silinecekAdres){
    node* head=liste;
    while(head->next!=silinecekAdres)
        head=head->next;
    node* temp=head->next;
    node* head2=temp->next;
    head->next=head2;
    head2->prev=head;
    free(temp);
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
    node* l=NULL;
    for (int i = 1; i < 11; i++)
        l=dugumEkle(l,5*i);
    node* silinecekAdres=l->next->next->next;
    yazdir(l);
    aradanAdreseGoreSil(l,silinecekAdres);
    cout<<endl;
    yazdir(l);
    cout<<"ELEMAN SAYISI: "<<elemanSayisi(l);
    system("pause");
    return 0;
}