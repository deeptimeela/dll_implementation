
#include <stdio.h>
#include <stdlib.h>


struct node {
	int data; // represents data part of the node
	struct node *previous_node, *next_node; // pointer to previous_node node and the next_node node
};
struct node* root = NULL; // root points to the start of the DLL


void traverse()
{
	
	if (root == NULL) // list is empty
	{
		printf("\nList is empty AND has no contents\n");
		return;
	}
	
	struct node* temporaryorary; // temporary point to traverse
	temporaryorary = root; // traversal starting from the root/start
	while (temporaryorary != NULL) {
		printf("Data = %d\n", temporaryorary->data);
		temporaryorary = temporaryorary->next_node;
	}
}


void insertAtFront() // insertion in a DLL @FRONT 
{
	int data;
	struct node* temporary;
	temporary = (struct node*)malloc(sizeof(struct node)); // creating node
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temporary->data = data; 
	temporary->previous_node = NULL;

	// Pointer of temporary will be
	// assigned to start
	temporary->next_node = root; // temporary next_node should point to the first node in the DLL
	root = temporary;
}


void insertAtEnd() //inserting @end of dll
{
	int data;
	struct node *temporary, *trav;
	temporary = (struct node*)malloc(sizeof(struct node));
	temporary->previous_node = NULL;
	temporary->next_node = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temporary->data = data;
	temporary->next_node = NULL;
	trav = root;

	// If start is NULL
	if (root == NULL) {

		root = temporary;
	}

	// Changes Links
	else {
		while (trav->next_node != NULL)
			trav = trav->next_node;
		temporary->previous_node = trav;
		trav->next_node = temporary;
	}
}


void insertAtPosition() //inserting at a particular position in DLL
{
	int data, pos, i = 1;
	struct node *temporary, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next_node = NULL;
	newnode->previous_node = NULL;

	// Enter the position and data
	printf("\nEnter position : ");
	scanf("%d", &pos);
	

	// If start==NULL,
	if (root == NULL) {
		root = newnode;
		newnode->previous_node = NULL;
		newnode->next_node = NULL;
	}

	// If position==1,
	else if (pos == 1) {
	
	insertAtFront();
	}


	else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->data = data;
	temporary = root;
		while (i < pos - 1) {
			temporary = temporary->next_node;
			i++;
		}
		newnode->next_node = temporary->next_node;
		newnode->previous_node = temporary;
		temporary->next_node = newnode;
		temporary->next_node->previous_node = newnode;
	}
}

// function to delete the first node of the dll, simply delete the node and make root point to the 1st node-> next_node, make previous_node as null and thats all 
void deleteFirst()
{
	struct node* temporary;
	if (root == NULL) // if it is the only node in dll
		printf("\nList is empty\n");
	else {
		temporary = root;
		root = root->next_node;
		if (root != NULL)
			root->previous_node = NULL;
		free(temporary);
	}
}

/// function to delete from the end of the Dll, traverse till the end now simply make second last node next_node= null 
void deleteEnd()
{
	struct node* temporary;
	if (root == NULL)
		printf("\nList is empty\n");
	temporary = root;
	while (temporary->next_node != NULL)
		temporary = temporary->next_node;
	if (root->next_node == NULL) // if it is the only node in the Dll
		root = NULL;
	else {
		temporary->previous_node->next_node = NULL;
		free(temporary);
	}
}


void deletePosition()
{
	int pos, i = 1;
	struct node *temporary, *position;
	temporary = root;

	// If DLL is empty
	if (root == NULL)
		printf("\nList is empty\n");

	else {
	
		printf("\nEnter position : ");
		scanf("%d", &pos);

		
		if (pos == 1) {
			deleteFirst(); 
			if (root != NULL) {
				root->previous_node = NULL;
			}
			free(position);
			return;
		}

		
		while (i < pos - 1) {
			temporary = temporary->next_node;
			i++;
		}
		
		position = temporary->next_node;
		if (position->next_node != NULL)
			position->next_node->previous_node = temporary;
		temporary->next_node = position->next_node;

	
		free(position);
	}
}


int main()
{
	int choice;
	while (1) {

		printf("\n\t1 display @list\n");
		printf("\t2 insert @start\n");
		printf("\t3 insert @end\n");
		printf("\t4 insert @given pos\n");
		printf("\t5 delete @first \n");
		printf("\t6 delete @last \n");
		printf("\t7 delete @given pos\n");
		printf("\t8 EXIT\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;

		case 8:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}
