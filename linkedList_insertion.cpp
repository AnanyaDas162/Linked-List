#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}node;
void display(node *head)
{
    cout << "Now, the linked list is "<< endl;
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp -> next;
    }
    cout << endl;
}
node* insertion_beginning(node *head)
{
    node *newnode;
    newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    newnode -> next = NULL;
    cout << "Enter the data" << endl;
    cin >> newnode->data;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode -> next = head;
        head = newnode;
    }
    display(head);
    return head;
}
node* insertion_end(node *head)
{
    node *newnode;
    newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    newnode -> next = NULL;
    cout << "Enter the data" << endl;
    cin >> newnode->data;
    node *temp;
    temp = head;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
     display(head);
     return head;
}
node *insertion_middle(node *head)
{
    node *newnode;
    int pos;
    newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    newnode -> next = NULL;
    cout << "Enter the data" << endl;
    cin >> newnode->data;
    node *temp;
    temp = head;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        cout << "Enter the position where you wanna insert the new node " << endl;
        cin >> pos;
        for (int i = 1; i < pos-1; i ++)
        {
            temp = temp -> next;
        }
        newnode->next = temp -> next;
        temp -> next = newnode;
    }
     display(head);
     return head;
}
int main()
{
    node *head, *newnode;
    head = NULL;
    newnode = NULL;
    int n = 1;
    cout << "Enter 1 for insertion at beginning.....2 for insertion at middle.....3 for insertion at end" << endl;
    cout << "Enter 0 for end" << endl;
    while (n != 0)
    {
        cout << "Enter your choice" << endl;
        cin >> n;
        if (n==1)
        {
            head = insertion_beginning(head);
        }
        else if (n==2)
        {
            head = insertion_middle(head);
        }
        else if (n==3)
        {
            head = insertion_end(head);
        }
        else if (n==0)
        {
            cout << "The program has been ended" << endl;
        }
        else 
        {
            cout << "Wrong Choice" << endl;
        }
    }
}