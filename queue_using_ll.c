#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int info;
	struct node *next;
}node;
void enqueue(node **head, node **tail) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if(temp==NULL) {
		printf("Overflow");
	}
	else {
		int info;
		scanf("%d", &temp->info);
		if(*head==NULL && *tail==NULL) {
			temp -> next = *tail;
			*head = temp;
			*tail = temp;
		}
		else {
			temp -> next = NULL;
			(*tail) -> next = temp;
			*tail = temp;
		}
	}
}
void dequeue(node **head, node **tail) {
	if(*head==NULL) {
		printf("Empty");
	} else {
		if((*head)->next == NULL) {
			*head=NULL;
			*tail = NULL;
		}
		else {
			*head = (*head) -> next;
		}
	}
}
void display(node *head) {
	if(head==NULL) {
		printf("Empty");
	} else {
		node *ptr;
		ptr = head;
		while(ptr!=NULL) {
			printf("%d", ptr->info);
			ptr = ptr -> next;
		}
	}
}
int main() {
	node *head=NULL, *tail=head;
	int choice;
	while(1) {
		scanf("%d", &choice);
		switch(choice) {
			case 1:
			enqueue(&head, &tail);
			break;
			case 2:
			dequeue(&head, &tail);
			break;
			case 3:
			display(head);
			break;
			case 4:
			exit(1);
			break;
			default:
			printf("Invalid");
		}
	}
	return 0;
}
