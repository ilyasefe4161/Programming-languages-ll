#include<stdio.h>
#include<stdlib.h>

struct node {
int number;
struct node * next;
};
struct node *head = NULL;
struct node *tail = NULL;


addeven(int number){
	if(head==NULL){
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->number=number;
		new->next=NULL;
		
		tail=head=new;
	}
	else{
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->number=number;
		new->next=head;
		head=new;
	}
	return 0;
}

addodd(int number){
	if(head==NULL){
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->number=number;
		new->next=NULL;
		
		head=tail=new;
	}
	else{
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->number=number;
		new->next=NULL;	
		tail->next=new;
		tail=new;
		}
	return 0;
}

int print(){
    printf("Linked List: ");
    struct node *index = head;
    while(index!=NULL){
        printf("%d - ", index->number);
        index = index->next;
    }
    printf("\n");
    return 0;
}

int main(){
	int n;
	printf("enter a number(for exit enter -1): ");
	scanf("%d",&n);
	while(n!=-1){
		if(n%2!=0)
		addodd(n);
		else
		addeven(n);
		printf("enter a number(for exit enter -1): ");
		scanf("%d",&n);
	}
	print();
	return 0;
}
