#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *createlist_and_reverseList (node *head, node *temp, node *newnode, int n);
void displaylist (node *HEAD);
int main()
{
	int n ,i;
	node *HEAD;
	HEAD = NULL;
	printf("\n Enter the number of nodes in the linked list: ");
	scanf("%d", &n);  // In createlist function, by using malloc function newnode is created 'n' times. //
	node *head;
	node *newnode;
	node *temp;
	HEAD = createlist_and_reverseList (head, newnode, temp, n);  // in HEAD in this main function, the address of the head is stored from the createlist function. FUNCTION CALL //
	displaylist(HEAD);
	return 0;
}
node * createlist_and_reverseList (node *head, node *newnode, node *temp, int n)
{
	head = NULL;
	newnode = NULL;
	temp = NULL;
	int i;
	for (i = 0; i < n; i ++)
	{
		newnode = (node*)malloc(sizeof (node));  // creates a new momory block during the run time and returns a void pointer and this is typecasted to struct node type pointer.  //
		printf("\n Enter the data for node no. %d: ",i + 1);
		scanf("%d", &(newnode -> data)); // The integer value is stored in the newly created node. //
		newnode -> next = NULL;      //  NULL is stored in the address part of the newly created node.  //
		if ( head == NULL)          //   Only For the first node of the linked list.    //
		{
			head = temp = newnode;   // Initially head was zero and now The address of the first node is stored in head permenently i.e. the 1st node is linked in the list.   //
		}
		else         //     Else part is executed from the second node to the last node.   //
		{
			temp->next = newnode;    //   After linking the first node in the list and then after creating the second node, now temp is having the address of the first node and newnode is having the address of the second node by the malloc function. And this address of the new node is assigned in the this address part of the first node. Thus the 2nd node is linked.   //
			temp = newnode;         // Then by using malloc function the third node is created and its address is now stored in the newnode which is assigned in temp.  //
		}
	}
	int arr[n];
	temp = head;
	i = 0;
	while (temp != NULL)
	{
		arr[i] = temp -> data;
		temp = temp -> next;
		i ++;
	}
	i = n - 1;
	temp = head;
	while (temp != NULL)
	{
		temp -> data = arr[i];
		temp = temp -> next;
		i --;
	}
	return head;
}
void displaylist (node *HEAD)   // head pointer is coming from createlist function.   //
{
	node *temp = HEAD;      //  temp pointer is pointing to a node which is head.  //
	printf("\n **********The REVERSED LINKED LIST is************ \n");
	while (temp != NULL)    // here, temp -> next is not written as for that, the last node will not be printed. //
	{
		printf("%d ->",temp -> data );
		temp = temp -> next;   // The address of the next node is stored in the temp and the loop is executed.   //
	}
}
