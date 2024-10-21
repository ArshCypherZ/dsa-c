#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int info;
	struct node *next;
}node;
void push(node **head, node **tail) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if(temp==NULL) {
		printf("Overflow");
	}
	else {
		int info;
		scanf("%d", &info);
		if(*head==NULL && *tail==NULL) {
			temp -> next = *tail;
			*head = temp;
			*tail = temp;
		}
		else {
			temp -> next = *head;
			*head = temp;
		}
	}
}
void pop(node **head, node **tail) {
	if(*head==NULL) {
		printf("Empty");
	} else {
		*head = (*head) -> next;
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
			push(&head, &tail);
			break;
			case 2:
			pop(&head, &tail);
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
