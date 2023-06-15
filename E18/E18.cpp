#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* prev;
};

node* nodeOlustur(int veri){
    node* yeniNode=new node;
    yeniNode->data=veri;
    yeniNode->next=yeniNode;
    yeniNode->prev=yeniNode;
    return yeniNode;
}

node* sonaNodeEkle(node* liste, node* yeni){
    if(liste==NULL)
        return yeni;
    else
    {
        node* head=liste;
        while(head->next!=liste)
            head=head->next;
        head->next=yeni;
        yeni->next=liste;
        yeni->prev=head;
        liste->prev=yeni;
        return liste;
    }
}

void yazdir(node* liste){
    node* head=liste;
    do
    {
       cout<<head->data<<" ";
       head=head->next; 
    } while (head!=liste);
}

void yazdirAyrintili(node* liste){
    node* head=liste;
    int n=1;
    do
    {
       cout<<n<<". NODE=> ADRESI: "<<head<<" PREV: "<<head->prev<<" DATA: "<<head->data<<" NEXT: "<<head->next<<endl;
       n++;
       head=head->next; 
    } while (head!=liste);
}

void terstenYazdir(node* liste){
    node* last=liste->prev;
    while(last!=liste->prev)
    {
        cout<<last->data<<" ";
        last=last->prev;
    }
}

node* basaNodeEkle(node* liste,node* yeni){
    node* head=liste;
    node* last=liste->prev;
    yeni->next=head;
    yeni->prev=last;
    last->next=yeni;
    head->prev=yeni;
    return yeni;
}

node* sonaNodeEkle2(node* liste,node* yeni){
    node* head=liste->prev;
    yeni->next=liste;
    yeni->prev=head;
    head->next=yeni;
    liste->prev=yeni;
    return liste;
}

int main()
{
    node* l=NULL;
    for(int i=10;i<101;i+=10)
        l=sonaNodeEkle(l,nodeOlustur(i));
    l=sonaNodeEkle2(l,nodeOlustur(5));
    //l=basaNodeEkle(l,nodeOlustur(5));
    yazdir(l);
    //yazdirAyrintili(l);
    //terstenYazdir(l);
    return 0;
}