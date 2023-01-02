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
void insert(Node **p,int pos, int ele)
{
    if(pos==1)
    {
        Node *neww=new Node;
        neww->data=ele;
        neww->next=*p;
        *p=neww;
        return;
    }
    else
    {
        Node *neww=new Node;
        neww->data=ele;
        Node *q=*p;
        for(int i=0;i<pos-2;i++)
         q=q->next;
        neww->next=q->next;
        q->next=neww;
        return;
    }
}
int main()
{
    int arr[] = {6, 5, 2, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]); // finds size of array without asking the user
    Node* root = arrayToList(arr, n); // creates a linked list replicating the array
    insert(&root,6,10);
    display(root);
    return 0;
}