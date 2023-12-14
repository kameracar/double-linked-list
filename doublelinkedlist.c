#include <stdio.h>
#include <stdlib.h>

struct linkedlist{
	struct linkedlist * prev;
	int data;
	struct linkedlist *next;
};

typedef struct linkedlist node;
node * start=NULL;
node * getnode(){
	node * newnode;
	newnode = (node*)malloc(sizeof(node));
	printf("Enter the data\n");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void createList(int n){
	int i;
	node * newnode;
	node * temp;
	temp=start;
	for(i=0;i<n;i++){
		newnode=getnode();
		if(start==NULL){
			start=newnode;
		}else{
			temp=start;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
		}
	}
}
void display(){
	node * disp;
	disp=start;
	do{
		printf("%d\n",disp->data);
		disp=disp->next;
	}while(disp!=NULL);
}
void displayreverse(){
	node * bas;
	bas=start;
	while(bas->next!=NULL){
		bas=bas->next;
	}
	do{
		printf("%d\n",bas->data);
		bas=bas->prev;
	}while(bas!=NULL);
}	
int main() {
	createList(5);
	display();
	displayreverse();
}
