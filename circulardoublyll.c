#include<stdio.h>
#include<stdlib.h>
struct CDNode {
	int info;
	struct CDNode *next, *prev;
};
struct CDNode * insertatBeginning(struct CDNode * head) {
	struct CDNode *temp;
	temp = (struct CDNode *)malloc(sizeof(struct CDNode));
	if(temp==NULL) {
		printf("Overflow.");
	}
	else {
		printf("\nEnter value to be inserted: ");
		scanf("%d", &(temp->info));
		if(head==NULL) {
			head = temp;
			temp -> next = head;
			temp -> prev = head;
		}
		else {
			struct CDNode *ptr;
			ptr = head;
			while(ptr->next != head) {
				ptr = ptr->next;
			}
			ptr -> next = temp;
			temp -> prev = ptr;
			head -> prev = temp;
			temp -> next = head;
			head = temp;
		}
	}
	return head;
}
struct CDNode * insertatLast(struct CDNode * head) {
	struct CDNode *temp;
	temp = (struct CDNode *)malloc(sizeof(struct CDNode));
	if(temp==NULL) {
		printf("\nOverflow.");
	}
	else {
		printf("\nEnter value to be inserted: ");
		scanf("%d", &(temp -> info));
		if(head==NULL) {
			head = temp;
			temp -> next = head;
			temp -> prev = head;
		} else {
			struct CDNode *ptr;
			ptr = head;
			while(ptr->next!=head) {
				ptr = ptr -> next;
			}
			ptr -> next = temp;
			temp -> prev = ptr;
			head -> prev = temp;
			temp -> next = head;
		}
	}
	return head;
}
struct CDNode * deleteatBeginning(struct CDNode * head) {
	struct CDNode *ptr;
	if(head==NULL) {
		printf("\nUnderflow.");
	}
	else if(head -> next == head) {
		head = NULL;
		free(head);
		printf("\nNode deleted.");
	}
	else {
		ptr = head;
		while(ptr->next !=head) {
			ptr= ptr -> next;
		}
		ptr -> next = head -> next;
		head -> next -> prev = ptr;
		free(head);
		head = ptr -> next;
		printf("\nNode deleted.");
	}
	return head;
}
struct CDNode * deleteatLast(struct CDNode * head) {
	struct CDNode *ptr;
	if(head==NULL) {
		printf("\nUnderflow.");
	} else if (head -> next == head) {
		head = NULL;
		free(head);
		printf("\nNode deleted.");
	} else {
		ptr = head;
		while(ptr -> next != head) {
			ptr = ptr -> next;
		} 
		ptr -> prev -> next = head;
		head -> prev = ptr -> prev;
		free(ptr);
		printf("\nNode deleted.");
	}
	return head;
}
void display(struct CDNode *head) {
	struct CDNode *ptr;
	ptr = head;
	if(head==NULL) {
		printf("\nUnderflow.");
	}
	else {
		while(ptr->next != head) {
			printf("%d\n", ptr->info);
			ptr = ptr -> next;
		}
		printf("%d\n",ptr-> info);
	}
}
void main() {
	struct CDNode *head=NULL;
	int choice;
	while(1) {
		printf("\nEnter 1 for insertion at beginning, 2 for insertion at end, 3 for deletion at beginning, 4 for deletion at end, 5 for display and 6 for exit.");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				head = insertatBeginning(head);
				break;
			case 2:
				head = insertatLast(head);
				break;
			case 3:
				head = deleteatBeginning(head);
				break;
			case 4:
				head = deleteatLast(head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				printf("\nExiting....");
				exit(1);
			default:
				printf("\nWrong choice.");
		}
	}
}
