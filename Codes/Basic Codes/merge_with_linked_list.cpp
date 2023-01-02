#include <iostream>
using namespace std;
  
class Node {
    public:
    int data;
    Node *next;
};
  
void insert(Node** root, int item) // creates a linked list starting from last element and linking it from frontside
{
    Node* temp = new Node;
    temp->data = item;
    temp->next = *root;
    *root = temp;
}
void display(Node* root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }
}
  
Node *arrayToList(int arr[], int n)
{
    Node *root = NULL;
    for (int i = n-1; i >= 0 ; i--) // we create the last element of linked list first and connect it from frontside
        insert(&root, arr[i]); // we have to modify the value of root pointer so that it points to a linked list and not NULL
    return root;               // so call by value wont work, we use call by address here
}
Node *mergee(Node *p, Node *q)
{
    Node *a=NULL;
    Node *r=NULL;
    if(p->data<q->data)
    {
        a=p;
        r=p;
        p=p->next;
        r->next=NULL;
    }
    else
    {
        a=q;
        r=q;
        q=q->next;
        r->next=NULL;
    }
    while(p!=NULL && q!=NULL)
    {
    if(p->data<q->data)
    {
        r->next=p;
        r=p;
        p=p->next;
        r->next=NULL;
    }
    else
    {
        r->next=q;
        r=q;
        q=q->next;
        r->next=NULL;
    }
    }
    if(p==NULL)
     r->next=q;
    else r->next=p;
    return a;
    
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5,8,8,10};
    int brr[] = {2,5,6,7,10,10,10,12};
    int n = sizeof(arr) / sizeof(arr[0]); // finds size of array without asking the user
    int m = sizeof(brr) / sizeof(brr[0]);
    Node *root_a = arrayToList(arr, n); // creates a linked list replicating the array
    Node *root_b = arrayToList(brr, m);
    Node *root_c=mergee(root_a,root_b);
    display(root_c);
    return 0;
}