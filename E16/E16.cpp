#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* nodeEkle(node* liste, int data) {
    if (liste == NULL) {
        liste = new node;
        liste->data = data;
        liste->next = liste;
    }
    else if (liste == liste->next) {
        node* yeniNode = new node;
        yeniNode->data = data;
        yeniNode->next = liste;
        liste->next = yeniNode;
    }
    else {
        node* head = liste;
        while (head->next != liste)
            head = head->next;
        node* yeniNode = new node;
        yeniNode->next = liste;
        yeniNode->data = data;
        head->next = yeniNode;
    }
    return liste;
}

void yazdir(node* liste){
    node* head=liste;
    do
    {
        cout<<head->data<<" ";
        head=head->next;
    }while(head!=liste);
}

void yazdirAyrintili(node* liste){
    node* head=liste;
    int n=1;
    do
    {
        cout<<"n"<<n<<": => n->: "<<head<<" n->data: "<<head->data<<" n->next: "<<head->next<<endl;
        head=head->next;
        n++;
    }while(head!=liste);
}

int main()
{
    node* l=NULL;
    for (int i = 1; i < 10; i++)
        l=nodeEkle(l,i*10);
    //yazdir(l);
    yazdirAyrintili(l);
    system("pause");
    return 0;
}