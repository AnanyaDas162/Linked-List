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
node *createnode (node *head)
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
    cout << "Enter 1 to add node to the linked list and enter 0 to end the addition and enter 2 for the sorted linked list"<< endl;
    while(choice)
    {
        cout << "Enter your choice ::" << endl;
        cin >> choice;
        if (choice == 1)
        {
             head = createnode(head);
             count = display(head, count);
        }
        else if (choice == 2)
        {
            head = sort_Linked_list(head, count);
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