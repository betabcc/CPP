#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* nodeEkle(node* agac,int veri){
    if(agac==NULL)
    {
        agac=new node;
        agac->data=veri;
        agac->left=NULL;
        agac->right=NULL;
    }
    else
    {
        if(veri<agac->data)
            agac->left=nodeEkle(agac->left,veri);
        else
            agac->right=nodeEkle(agac->right,veri);
    }
    return agac;
}

void inorderGezinti(node* agac){
    if(agac!=NULL)
    {
        inorderGezinti(agac->left);
        cout<<agac->data<<" ";
        inorderGezinti(agac->right);

        // TERSİ
        // inorderGezinti(agac->right);
        // cout<<agac->data<<" ";
        // inorderGezinti(agac->left);
    }
}
void preorderGezinti(node* agac){
    if(agac!=NULL)
    {
        cout<<agac->data<<" ";
        preorderGezinti(agac->left);
        preorderGezinti(agac->right);
    }
}
void postorderGezinti(node* agac)
{
    if(agac!=NULL)
    {
        postorderGezinti(agac->left);
        postorderGezinti(agac->right);
        cout<<agac->data<<" ";
    }
}

void yaprakMı(node* agac){
    if(agac!=NULL)
    {
        yaprakMı(agac->left);
        if(agac->left==NULL && agac->right==NULL)
            cout<<agac->data<<" ";
        yaprakMı(agac->right);
    }
}

int enBuyukDeger(node* agac)
{
    node* head=agac;
    if(head==NULL)
        return 0;
    else
    {
        while(head->right!=NULL)
            head=head->right;
        return head->data;
    }
}

node* enKucukDegerliNodeBul(node* agac){
    node* temp=agac;
    while(temp && temp->left!=NULL)
        temp=temp->left;
    return temp;
}

node* nodeSil(node* agac,int veri){
    if(agac==NULL)
        return agac;
    if(veri<agac->data)
        agac->left=nodeSil(agac->left,veri);
    else if(veri>agac->data)
        agac->right=nodeSil(agac->right,veri);
    else{
        if(agac->left==NULL&&agac->right==NULL)
            return NULL;
        else if(agac->left==NULL&&agac->right!=NULL)
        {
            node* temp=agac->right;
            free(agac);
            return temp;
        }
        else if(agac->left!=NULL&&agac->right==NULL)
        {
            node* temp=agac->left;
            free(agac);
            return temp;
        }
        else{
            node* temp=enKucukDegerliNodeBul(agac->right);
            temp->left=agac->left;
            node* temp2=agac->right;
            free(agac);
            return temp2;
        }
    }
    return agac;
}

int main()
{
    node* tree=NULL;
    tree=nodeEkle(tree,25);
    tree=nodeEkle(tree,14);
    tree=nodeEkle(tree,40);
    tree=nodeEkle(tree,7);
    tree=nodeEkle(tree,23);
    tree=nodeEkle(tree,34);
    tree=nodeEkle(tree,48);
    tree=nodeEkle(tree,5);
    tree=nodeEkle(tree,10);
    tree=nodeEkle(tree,17);
    tree=nodeEkle(tree,24);
    tree=nodeEkle(tree,36);
    tree=nodeEkle(tree,25);
    tree=nodeEkle(tree,7);
    tree=nodeEkle(tree,23);
    tree=nodeSil(tree,23);
    tree=nodeSil(tree,23);
    tree=nodeSil(tree,100);
    inorderGezinti(tree);
    // preorderGezinti(tree);
    // postorderGezinti(tree);
    // yaprakMı(tree);
    cout<<endl;
    system("pause");
    return 0;
}