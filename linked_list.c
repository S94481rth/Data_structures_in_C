
#include <stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node* link;
};
struct node* head = NULL;
void traverse()
{
    struct node* temp;
 
    
    if (head == NULL)
        printf("\nList is empty\n");
 
    
    else {
        temp = head;
        while (temp != NULL) {
            printf("Data = %d\n",
                   temp->value);
            temp = temp->link;
        }
    }
}

void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	temp->value = data;
	temp->link = head;
	head = temp;
}


void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));


	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);


	temp->link = 0;
	temp->value = data;
	head = head;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}

void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	
	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);

	
	temp = head;
	newnode->value = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}
int main()
{
	int choice;
	while (1) {

		
		printf("\t1For insertion at"
			" heading\n");
		printf("\t2 For insertion at"
			" end\n");
		printf("\t3 For insertion at "
			"any position\n");
			printf("\t4 to exit\n");
			printf("\t5 to display\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			insertAtFront();
			break;
		case 2:
			insertAtEnd();
			break;
		case 3:
			insertAtPosition();
			break;
		case 4:
			exit(1);
			break;
	    case 5: traverse();
	    break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
