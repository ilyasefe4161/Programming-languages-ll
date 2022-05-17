#include<stdio.h>
#include<stdlib.h>

struct node {
int number;
struct node * next;
};

struct node* cutlastaddhead(struct node** head)
{
	if (*head == NULL || (*head)->next == NULL)
		return 0;

	struct node *secLast = NULL;
	struct node *last = *head;

	while (last->next != NULL)
	{
		secLast = last;
		last = last->next;
	}
	secLast->next = NULL;
	last->next = *head;
	*head = last;
}

void push(struct node** head, int newnumber)
{
	struct node* newnode =(struct node*) malloc(sizeof(struct node));
	newnode->number = newnumber;
	newnode->next = (*head);
	(*head) = newnode;
}

void printList(struct node *node)
{
	while(node != NULL)
	{
		printf("%d ", node->number);
		node = node->next;
	}
}

int main()
{
	struct node *start = NULL;

	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	printf("\n Linked list before moving last to front\n");
	printList(start);

	cutlastaddhead(&start);

	printf("\n Linked list after removing last to front\n");
	printList(start);

	return 0;
}
