#include <iostream>
using namespace std;

struct node
{
    int data; 
    node* next; 
};

int main()
{
    node* n1=new node;
    n1->data=10;
    n1->next=NULL;
    node* n2=new node;
    n2->data=20;
    n2->next=NULL;
    n1->next=n2;
    cout << "n1:        " << n1 << endl;
    cout << "n1->data:  " << n1->data <<endl;
    cout << "n1->next:  " << n1->next <<endl;
    cout << "n2:        " << n2 << endl;
    cout << "n2->data:  " << n2->data <<endl;
    cout << "n2->next:  " << n2->next <<endl;
    system ("pause");
    return 0;
}