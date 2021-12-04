#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *createlist(node *head, node *newnode, node *temp, int n);
node *insert_beg(node *head, node *tail, node *temp);
node *insert_last(node *head, node *tail, node *temp);
node *insert_particular_pos(node *head, node *newnode, node *temp, int n, node *tail);
node *delete_beg(node *head, node *tail, node *temp);
node *delete_last(node *head, node *tail, node *temp);
node *displaylist(node *head, node *temp);
int main()
{
	node *head;
	node *temp;
	node *newnode;
	node *tail;
	head = NULL;
	int n, i, choice;
    do
    {
    	printf("\n *******************MAIN MENU**********************");
    	printf("\n We are determining the first node of the circular linked list as head and the last node as the tail ");
	    printf("\n <1> For creating the CIRCULAR LINKED LIST");
	    printf("\n <2> For inserting a node before the head");
	    printf("\n <3> For inserting a node at the end of the tail");
	    printf("\n <4> For displaying the whole circular linked list ");
	    printf("\n <5> For inserting a node at a particular position");
	    printf("\n <6> For deleting the first node ");
	    printf("\n <7> For deleting the last node ");
	    printf("\n <10> For exiting from the loop ");
	    printf("\n\n Enter your choice : ");
	    scanf("%d", &choice);
	    switch(choice)
	    {
	    	case 1 : head = createlist(head, newnode, temp, n);
	    	         printf("\n Circular Link List created");
	    	         break;
	    	case 2 : head = insert_beg(head, tail, temp);     
			         printf("\n The newnode is inserted before the head");
					 break;
			case 3 : head = insert_last(head, tail, temp);	
			         printf("\n The newnode is inserted after the tail");
					 break;	 
			case 4 : head = displaylist(head, temp);
			         printf("\n The whole circular linked list is displaying ");
					 break;		   
			case 5 : head = insert_particular_pos(head, newnode, temp, n, tail);
			         printf("\n The newnode is inserted at the particular position ");
					 break;	
			case 6 : head = delete_beg(head, tail, temp);
			         printf("\n The first node is deleted ");
					 break; 
			case 7 : head = delete_last(head, tail, temp);
			         printf("\n The last node is deleted ");
					 break; 
			case 10: printf("\n The program is ended \n");	
			         break;
			default: printf("\n WRONG CHOICE \n");
			         break;
		}
	}while (choice != 10);
	return 0;
}
node *createlist(node *head, node *newnode, node *temp, int n)
{
	int i;
	head = NULL;
	newnode = NULL;
	temp = NULL;
	printf("\n Enter the number of nodes: ");
	scanf("%d", &n);
	for (i = 0; i < n; i ++)
	{
		newnode = (node *) malloc (sizeof (node));
		printf("\n Enter the data for the node no %d : ", i + 1);
		scanf("%d", &newnode -> data);
		newnode -> next = NULL;
		if (head == NULL)
		{
			head = temp = newnode;
		}
		else
		{
			temp -> next = newnode;
			temp = newnode;
		}
	}
	temp -> next = head;
	return head;
}

node *insert_beg(node *head, node *tail, node *temp)
{
	node *newnode = NULL;
	temp = NULL;
	tail = NULL;
	newnode = (node *) malloc (sizeof (node));
	printf("\n Enter the data for the node  : ");
	scanf("%d", &newnode -> data);
	newnode -> next = NULL;
	temp = head;
	if (head == NULL)
	{
	    head = newnode;
	    tail = newnode;
	    head -> next = head;
	}
	else
	{
	    while (temp -> next != head)
	   {
	    	temp = temp -> next;
	   }
    	tail = temp;
	    tail -> next = newnode;
	    newnode -> next = head;
	    head = newnode;
	}
	return head;
}
node *insert_last(node *head, node *tail, node *temp)
{
	node *newnode = NULL;
	tail = NULL;
	temp = NULL;
	newnode = (node *) malloc (sizeof (node));
	printf("\n Enter the data for the node  : ");
	scanf("%d", &newnode -> data);
	newnode -> next = NULL;
	temp = head;
    if (head == NULL)
    {
        head = newnode;
        head -> next = head;
    }
    else
    {
        while (temp -> next != head)
	    {
	    	temp = temp -> next;
	    }
	    tail = temp;
	    tail -> next = newnode;
	    newnode -> next = head;
	    tail = newnode;
    }
	return head;
}
node *insert_particular_pos(node *head, node *newnode, node *temp, int n, node *tail)
{
	newnode = NULL;
	temp = NULL;
	int pos, i;
	newnode = (node *) malloc (sizeof (node));
	printf("\n Enter the data for the newnode : ");
	scanf("%d", &newnode -> data);
	int count = 0;
	node *t;
	t = head;
    if (head != NULL)
    {
        while (t -> next != head)
	    {
	       count ++;
	       t = t -> next;
	    }
	    count = count + 1;
    }
	printf ("\n %d", count);
	printf("\n Enter the position where you wanna insert a newnode : ");
	scanf("%d", &pos);
	if (pos > count + 1)
	{
	    printf("\n INVALID POSITION \n");
	}
	else
	{
	    if (head == NULL)
	    {
	        head = newnode;
	        head -> next = head;
	    }
	    else
	    {
	        if (pos == 1)
			{
				head = insert_beg(head, tail, temp);
			}
			else
			{
				temp = head;
	            for (i = 0; i < (pos - 2); i ++)
	            {
		            temp = temp -> next;
	            }
	            newnode -> next = temp -> next;
	            temp -> next = newnode;
			}
	    }
	}
	return head;
}
node *delete_beg(node *head, node *tail, node *temp)
{
	temp = head;
	node *p = head;
    if (head == NULL)
    {
        printf("\n The linked list is empty \n");
    }
    else
    {
        while (temp -> next != head)
	    {
		    temp = temp -> next;
	    }
	    temp -> next = head -> next;
	    head = head -> next;
	    free(p);
    }
	return head;
}
node *delete_last(node *head, node *tail, node *temp)
{
	temp = head;
	node *prev = NULL;
    if (head == NULL)
    {
        printf("\n The linked lust is empty!! \n");
    }
    else
    {
        while (temp -> next != head)
	    {
		    prev = temp;
		    temp = temp -> next;
	    }
    	prev -> next = temp -> next;
	    free(temp);
    }
	return head;
}
node *displaylist(node *head, node *temp)
{
	temp = head;
    if (head == NULL)
    {
    	printf("\n The CIRCULAR LINKED LIST is empty!");
	}
	else
	{
	    printf("\n The Circular Linked list is displaying: ");
		while (temp -> next != head)
	{
		printf("%d -> ", temp -> data);
		temp = temp -> next;
	}
	}
	printf("%d", temp -> data);
	return head;
}
