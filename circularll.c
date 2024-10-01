#include<stdio.h>
#include<stdlib.h>
struct CNode {
	int info;
	struct CNode *next;
};
struct CNode * insertatBeginning(struct CNode *head) {
	struct CNode *temp;
	temp = (struct CNode *)malloc(sizeof(struct CNode));
	if(temp==NULL) {
		printf("Overflow.");
	}
	else {
		printf("\nEnter value to be inserted: ");
		int value;
		scanf("%d", &value);
		if(head==NULL) {
			temp->next = temp;
			head = temp;
			temp -> info = value;
		}
		
		else {
			temp -> info = value;
			//printf("one 1");
			struct CNode *ptr;
			ptr = head;
			//printf("2");
			while(ptr -> next != head) {
				//printf("3");
				ptr = ptr -> next;
			}
			ptr -> next = temp;
			temp -> next = head;
			head = temp;
		
		/* temp -> next = ptr;
		temp = head;
		head = temp -> next; */
	}
	return head;
}
}
struct CNode * insertatLast(struct CNode *head) {
	struct CNode *temp;
	temp = (struct CNode *)malloc(sizeof(struct CNode));
	if(temp==NULL) {
		printf("Overflow.");
	}
	else {
		printf("\nEnter value:");
		scanf("%d", &(temp->info));
		struct CNode *ptr;
		ptr = head;
		if(head==NULL) {
			head = temp;
			temp -> next = temp;
		}
		else {
			while(ptr -> next != head) {
				ptr = ptr -> next;
			}
			temp -> next = head;
			ptr -> next = temp;
		}
	}
	return head;
}
struct CNode * deleteatBeginning(struct CNode *head) {
	if(head==NULL) {
		printf("Underflow.");
	}
	else if(head -> next == head) { // if only one node
		head = NULL;
	}
	else {
		struct CNode *ptr;
		ptr = head;
		while(ptr -> next != head) {
			ptr = ptr -> next;
		}
		struct CNode *p;
		ptr -> next = head -> next;
		p = head;
		head = head -> next;
		free(p);
	}
	return head;
}
struct CNode * deleteatLast(struct CNode *head) {
	if(head==NULL) {
		printf("Underflow.");
	}
	else if(head -> next == head) {
		head = NULL;
	}
	else {
		struct CNode *p1;
		p1 = head;
		while((p1 -> next)->next != head) {
			
			p1 = p1->next;
		}
		struct CNode *p;
		p = p1->next; 
		p1 -> next = head;
		free(p);
	}
return head;
}
void display(struct CNode *head) {
	if(head==NULL) {
		printf("Underflow.");
	} else {
		struct CNode *ptr;
		ptr = head;
		while(ptr -> next != head) {
			printf("%d", ptr -> info);
			ptr = ptr -> next;
		}
		printf("%d", ptr -> info);
	}
}
void main() {
	struct CNode *head=NULL;
	int choice;
	do {
		printf("\nEnter 1 for insert at beginning, 2 for insert at last, 3 for delete at beginning, 4 for delete at last, 5 for display, 6 for exit.");
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
				printf("\nExiting...");
				exit(1);
			default:
				printf("\nWrong choice, try again.");
				break;
		} 
	} while(1);
}
		
	
	
