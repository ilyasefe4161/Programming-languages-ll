#include<stdio.h>
#include<stdlib.h>

struct node {
int number;
struct node * next;
};
struct node *head=NULL;
struct node *tail=NULL;

int add(int number){
	if(head==NULL){
		struct node *new=(struct node*)malloc(sizeof(struct node));
		new->number=number;
		new->next=NULL;
		head=tail=new;
	}
	else{
		struct node *new=(struct node*)malloc(sizeof(struct node));
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

int deletemiddle(){
	struct node *index=head;
	struct node *prev=NULL;
	int i,counter=0;
	while(index!=NULL){
		index=index->next;
		counter++;
	}
	index=head;
	for(i=0;i<=(counter-1)/2;i++){
		prev=index;
		index=index->next;
	}
	deleteData(prev->number);
	return 0;
}

int deleteData(int alinan){
	struct node *prev=NULL;
	struct node *index=head;
	
	if(head==NULL){
		print("Linked list is empty");
		return 1;
	}
	
	if(head->number==alinan){
		struct node *t=head;
		head=head->next;
		free(t);
		return 1;
	}
	while(index!=NULL && index->number!=alinan){
		prev=index;
		index=index->next;
	}
	if(index==NULL){
		printf("data not found");
		return 1;
	}
	prev->next=index->next;
	
	if(tail->number==alinan){
		tail=prev;
	}
	free(index);
	return 0;
}

int main(){
struct node *r;
add(1);
add(2);
add(3);
add(4);
add(5);
add(6);
add(7);
print();
deletemiddle();
print();
return 0;	
}
