#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;

};
node *root;

struct node1
{
    node *data1;
    node1 *next;
};

class stacks
{
    public:
        node1 *top,*tail;
        stacks()
        {
            top=NULL;

        }
    void push(node *);
    node1* pop();
    void ins(node*,node*);
    void inorder(node*);
    void display();

};
void stacks::push(node *temp)
{
    node1 *t=new node1;
    t->data1=temp;
    t->next=NULL;

    if(top==NULL)
    {
        top=t;

    }
    else
    {
        t->next=top;
        top=t;

    }

}
node1* stacks::pop()
{
    node1 *temp;
    temp=top;
    top=top->next;
    return temp;

}
void stacks:: ins(node *root1,node *temp)
{

    if(root1==NULL)
    {
        root=temp;
        return;

    }
    if(root1->data>temp->data)
    {

        if(root1->left==NULL)
        {

            root1->left=temp;
        }
        else{
            ins(root1->left,temp);
        }
    }
    else{
        if(root1->right==NULL)
        {
            root1->right=temp;

        }
        else
        {

            ins(root1->right,temp);
        }
    }
}
void stacks::inorder(node* root1)
{
    if(root1==NULL)
    {

        cout<<"tree is empty"<<endl;
        return;
    }
    node* curr=root1;
    while(curr!=NULL || top!=NULL)
    {
        while(curr!=NULL)
        {
            push(curr);
            curr=curr->left;
        }
        curr=pop()->data1;
        cout<<curr->data<<" "<<endl;
        curr=curr->right;
    }

}
int main()
{
    stacks S;
    int i,n1,d,num;
    cout<<"Enter number of elements"<<endl;
    cin>>n1;
 for(int i=1;i<=n1;i++)
    {
          cin>>d;
       node *temp=new node;
    temp->data=d;
    temp->left=NULL;
    temp->right=NULL;
        S.ins(root,temp);
    }


    S.inorder(root);

}
