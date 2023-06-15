#include <iostream>
using namespace std;

struct node
{
    char c;
    node* next;
};

node* top=NULL;

void reset(){
    top=NULL;
}

void push(char veri){
    node* yeniNode=new node;
    yeniNode->c=veri;
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
        cout<<temp->c<<" ";
        free(temp);
    }
}

char peek(){
    return top->c;
}

int main()
{
    string ifade="a-(3+b*(c+d)-(k-3)/(c+x)+d*(a+(b+c)-2)+5*c";
    for (int i=0; i<ifade.size(); i++)
    {
        char karakter=ifade[i];
        if (karakter=='(')
            push(karakter);
        else if (karakter==')')
            pop();
    }
    if (top==NULL)
        cout<<"IFADE DOGRU";
    else
        cout<<"DEGIL";
    cout<<endl;
    system("pause");
    return 0;
}