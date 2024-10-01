#include<stdio.h>
#include<stdlib.h>
struct DNode {
	struct DNode *prev;
	int info;
	struct DNode *next;
};
struct DNode * insertAtBeginning(struct DNode *head) {
	struct DNode *temp;
	temp = (struct DNode *)malloc(sizeof(struct DNode));
	if(temp==NULL) {
		printf("Overflow.");
	}
	else
	{
		int item;
		temp->prev=NULL;
		temp->next=head;
		if(head!=NULL) head->prev = temp;
		head= temp;
		printf("\nEnter number: ");
		scanf("%d",&item);
		head->info = item;
	}
	return head;
}
struct DNode * insertAtLast(struct DNode *head) {
	struct DNode *temp;
	temp = (struct DNode *)malloc(sizeof(struct DNode));
	if(temp==NULL) {
		printf("Overflow.");
	}
	else if(head==NULL) {
		temp -> prev = temp -> next = NULL;
		head = temp;
		printf("\nEnter value to be inserted in the last: ");
		scanf("%d", &temp->info);
	}
	else {
		struct DNode *ptr;
		ptr = head;
		while(ptr->next!=NULL) {
			ptr = ptr -> next;
		}
		temp -> next = NULL;
		temp -> prev = ptr;

		ptr -> next = temp;
		printf("\nEnter value to be inserted in the last: ");
		scanf("%d", &temp->info);
	}
	return head;
}
struct DNode * insertAtMiddle(struct DNode *head) {
	struct DNode *temp;
	int count = 1;
	temp = (struct DNode *)malloc(sizeof(struct DNode));
	if(temp==NULL) {
		printf("Overflow.");
	}
	else if(head==NULL) {	
		temp -> next = NULL;
		temp -> prev = NULL;
		head = temp;
		printf("\nEnter value to be inserted in the middle: ");
		scanf("%d", &temp->info);
	}
	else { //
		struct DNode *ptr;
		ptr = head;
		while((ptr->next)!=NULL) {
			ptr = ptr -> next;
			count = count + 1;
		}
		
		int middle;
		middle = count/2;
		ptr=head;
		while(middle!=1) {
			ptr = ptr -> next;
			middle = middle - 1;
		}
		temp->next = ptr->next;
		temp-> prev = ptr;
		ptr -> next = temp;
		
		if ((temp->next)!=NULL)(temp->next)->prev = temp;
		
		
		printf("\nEnter value to be inserted in the middle: ");
		scanf("%d", &temp->info);
	}
	return head;
}
struct DNode * deletefromBeginning(struct DNode *head) {
	struct DNode *ptr;
	if(head==NULL) {
		printf("\nUnderflow.");
	}
	else if(head -> next == NULL) {
		head = NULL;
	}
	else {
		ptr = head;
		head = ptr -> next;
		head -> prev = NULL;
	}
	free(ptr);
	return head;
}
struct DNode * deletefromLast(struct DNode *head) {
	if(head==NULL) {
		printf("\nUnderflow.");
	}
	else if(head -> next == NULL) {
		head = NULL;
	} else {
		struct DNode *ptr;
		ptr = head;
		while(ptr -> next != NULL) {
			ptr = ptr -> next;
		}
		ptr -> prev -> next = NULL;
		free(ptr);
	}
	return head;
}
void traverse(struct DNode *head) {
	if(head == NULL) {
		printf("\nUnderflow.");
	}
	else {
		struct DNode *ptr;
		ptr = head;
		while(ptr!= NULL) {
			printf("%d", ptr -> info);
			ptr = ptr -> next;
		}
	}
}
void main() {
	struct DNode *head=NULL;
	int choice;
	do {
		printf("\nEnter 1 for insert at beginning, 2 for insert at last, 3 for insert at middle, 4 for display, 5 for delete at beginning, 6 for delete at last, 8 for exit.");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				head = insertAtBeginning(head);
				break;
			case 2:
				head = insertAtLast(head);
				break;
			case 3:
				head = insertAtMiddle(head);
				break;
			case 4:
				traverse(head);
				break;
			case 5:
				head = deletefromBeginning(head);
				break;
			case 6:
				head = deletefromLast(head);
				break;
			default:
				printf("\nExiting...");
				exit(1);
		} 
	} while(1);
}
		
	
