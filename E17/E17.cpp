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

node* basaNodeEkle(node* liste, int data){
    node* head=liste;
    while(head->next!=liste)
        head=head->next;
    node* yeniDugum=new node;
    yeniDugum->next;
    yeniDugum->data=data;
    yeniDugum->next=liste;
    head->next=yeniDugum;
    return yeniDugum;
}

int elemanSayisi(node* liste){
    int n=0;
    node* head=liste;
    do
    {
        n++;
        head=head->next;
    }while(head!=liste);
    return n;
}

node* bastanNodeSil(node* liste){
    node* head=liste;
    node* temp=liste;
    do
    {
        head=head->next;
    }while(head->next!=liste);
    node* bas=liste->next;
    head->next=bas;
    free(temp);
    return bas;
}

node* sondanNodeSil(node* liste){
    node* head=liste;
    while(head->next->next!=liste)
        head=head->next;
    node* temp=head->next;
    head->next=liste;
    free(temp);
    return liste;
}

node* sirayaGoreSilmeIslemi(node* liste,int sira){
    if (sira<=0||sira>elemanSayisi(liste))
    {
        return liste;
    }
    else if(sira==1)
    {
        return bastanNodeSil(liste);
    }
    else if(sira==elemanSayisi(liste))
    {
        return sondanNodeSil(liste);
    }
    else
    {
        node* head1=liste;
        for(int i=1;i<sira-1;i++)
            head1=head1->next;
        node* temp=head1->next;
        node* head2=temp->next;
        head1->next=head2;
        free(temp);
        return liste;
    }
}

int main()
{
    node* l=NULL;
    for (int i = 1; i < 10; i++)
        l=nodeEkle(l,i*10);
    //yazdir(l);
    //l=basaNodeEkle(l,5);
    //l=sondanNodeSil(l);
    //l=bastanNodeSil(l);
    l=sirayaGoreSilmeIslemi(l,4);
    //yazdirAyrintili(l);
    yazdir(l);
    cout<<elemanSayisi(l);
    system("pause");
    return 0;
}