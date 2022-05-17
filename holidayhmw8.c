#include<stdio.h>
#include<stdlib.h>

struct node{
	int age;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

int add(int age){
	if(head==NULL){
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->age=age;
		new->next=NULL;
		head=tail=new;
		
	}
	else{
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->age=age;
		new->next=NULL;	
		tail->next=new;
		tail=new;
	}
	return 0;
}

int print(){
	int i=0;
	printf("Linked List: ");
    struct node *index = head;
    while(i!=7){
        printf("%d - ", index->age);
        index = index->next;
        i++;
    }
    printf("\n");
    return 0;
}

int changeFirstAndLast(struct node **head)
{
    if (!*head || !(*head)->next)
        return 0;

    struct node **pp = &(*head)->next;

    while (*pp && (*pp)->next)
        pp = &(*pp)->next;

    struct node *tmp = *head;
    *head = *pp;
    *pp = tmp;

    (*head)->next = (*pp)->next;

    (*pp)->next = NULL;
	}



int main(){
add(1);
add(2);
add(3);
add(4);
add(5);
add(6);
add(7);
print();
changeFirstAndLast(&head);
print();

return 0;	
}
