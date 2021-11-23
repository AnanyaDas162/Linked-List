#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}node;
int display(node *head, int count)
{
    node *temp;
    temp = head;
    count = 0;
    cout <<"***********The LINKED LIST is displaying****************" << endl;
    while (temp != NULL)
    {
        cout << "\t" << temp->data;
        count ++;
        temp = temp -> next;
    }
    cout << endl;
    cout << "The number of nodes is :: " << count << endl;
    return count;
}
node *insert_beginning (node *head)
{
    node *newnode;
    newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    cout << "Enter the data : " << endl;
    cin >> newnode->data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    return head;
}
node *createnode_end (node *head)
{
    node *newnode;
    node *temp;
    temp = head;
    newnode = NULL;
    newnode = (node *)malloc(sizeof (node));
    cout << "Enter the data ::" << endl;
    cin >> newnode-> data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
    return head;
}
node *insert_anyPosition(node *head, int count)
{
    //cout << count;
    int pos;
    node *temp;
    node *newnode;
    newnode = NULL;
    newnode = (node *)malloc(sizeof(node));
    cout << "Enter the data ::" << endl;
    cin >> newnode -> data;
    newnode -> next = NULL;
    cout << "Enter the position to insert the new node ::" << endl;
    cin >> pos;
    temp = head;
    if (pos > count + 1)
    {
        cout << "This value for position is invalid" << endl;
    }
    else
    {
        if (pos == 1)
        {
            head = insert_beginning(head);
        }
        else
        {
            for (int i = 1; i < pos-1; i ++)
           {
                temp = temp -> next;
            }
            newnode->next = temp -> next;
            temp -> next = newnode;
        }
    }
    return head;
}
node *sort_Linked_list(node *head, int count)
{
    node *temp1;
    temp1 = head;
    int min = temp1 -> data;
    node *temp2;
    temp2 = head;
    node *ptr;
    ptr = head;
    for (int i = 0; i < count-1; i ++)
    {
        temp2 = temp1;
        min = temp2 -> data;
        ptr = temp2;
        for (int j = i + 1; j < count; j ++)
        {
            temp2 = temp2 -> next;
            if(temp2->data < min)
            {
                min = temp2->data;
                ptr = temp2;
            }
        }
        swap(temp1->data, ptr->data);
        temp1 = temp1 -> next;
    }
    return head;
}
int main()
{
    int choice = 1;
    int count = 0;
    node *head;
    head = NULL;
    while(choice)
    {
        cout << "Enter 1 to add node to the linked list at the end position"<< endl;
        cout << "Enter 3 to add node at the beginning" << endl;
        cout << "Enter 4 to add node at any position" << endl;
        cout << "Enter 2 to sort the linked list" << endl;
        cout << "Enter 0 to end the program" << endl;
        cout << "Enter your choice ::" << endl;
        cin >> choice;
        if (choice == 1)
        {
             head = createnode_end(head);
             count = display(head, count);
        }
        else if (choice == 2)
        {
            head = sort_Linked_list(head, count);
            count = display(head, count);
        }
        else if (choice == 3)
        {
            head = insert_beginning(head);
            count = display(head, count);
        }
        else if (choice == 4)
        {
            head = insert_anyPosition(head, count);
            count = display(head, count);
        }
        else if (choice == 0)
        {
            cout << "The program is ended" << endl;
        }
        else
        {
            cout << "WRONG CHOICE" << endl;
        }
    }
    return 0;
}