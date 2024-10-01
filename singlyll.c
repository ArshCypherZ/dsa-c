#include<stdlib.h>
#include<stdio.h>
struct sNode {
	int info;
	struct sNode *next;
} SN;
struct sNode * insertatBeginning(struct sNode *head) {
	struct sNode *temp;
	temp = (struct sNode *)malloc(sizeof(struct sNode));
	if(temp==NULL) {
		printf("\nOverflow.");
	}
	else {
		printf("\nEnter value to be inserted: ");
		scanf("%d", &(temp->info));
		temp -> next = head;
		head = temp;
	}
	return head;
}
struct sNode * insertatLast(struct sNode *head) {
	struct sNode *temp;
	temp = (struct sNode *)malloc(sizeof(struct sNode));
	if(temp==NULL) {
		printf("\nOverflow");
	}
	else if(head==NULL) {
		printf("\nEnter value to be inserted: ");
		scanf("%d", &(temp->info));
		head = temp;
		temp -> next = NULL;
	}
	else {
		struct sNode *p1;
		p1 = head;
		while((p1->next) != NULL) 
			p1 = p1 -> next;
		printf("\nEnter value to be inserted: ");
		scanf("%d", &(temp->info));
		temp -> next = NULL;
		p1 -> next = temp;
	}
	return head;
}
// if value of node is given
struct sNode * insertAfteraNode(struct sNode *head, int value) {
	struct sNode *temp, *ptr;
	temp = (struct sNode *)malloc(sizeof(struct sNode));
	if(temp==NULL) {
		printf("\nOverflow");
	}
	else {
		printf("\nEnter value to be inserted: ");
		scanf("%d", &(temp->info));
		ptr = head;
		while(ptr->info!=value) {
			ptr = ptr -> next;
		}
		temp -> next = ptr -> next;
		ptr -> next = temp;
	}
	return head;
}
struct sNode * display(struct sNode *head) {
	struct sNode *p1;
	if(head==NULL) {
		printf("\nLinked list is empty");
	}
	else {
		p1 = head;
		while(p1!=NULL) {
			printf("%d", p1->info);
			p1 = p1 -> next;
		}
	}
	return head;
}

struct sNode * deleteatBeginning(struct sNode *head) {
	if(head==NULL) {
		printf("\nUnderflow.");
	}
	else {
		head = head -> next;
	}
	return head;
}

struct sNode * deleteatLast(struct sNode *head) {
	struct sNode *p1, *p2;
	if(head==NULL) {
		printf("\nUnderflow.");
	}
	else {
		p2 = head;
		while(p2!= NULL) {
			p1 = p2;
			p2 = p2 -> next;
		}
		p1 -> next = NULL;
	}
	return head;
}
void main() {
	struct sNode *head=NULL;
	int value, choice;
	do {
		printf("\nEnter 1 for insert at beginning, 2 for insert at last, 3 for insert after a node if value is given, 4 for display, 5 for delete at beginning, 6 for delete at last, 8 for exit.");
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
				printf("\nEnter value of a node: ");
				scanf("%d", &value);
				head = insertAfteraNode(head, value);
				break;
			case 4:
				head = display(head);
				break;
			case 5:
				head = deleteatBeginning(head);
				break;
			case 6:
				head = deleteatLast(head);
				break;
			default:
				printf("\nExiting...");
				exit(1);
		} 
	} while(1);
}
		
