#include<stdio.h>
#include<stdlib.h>

void insertFront(int a[], int size, int *front, int *rear, int value) {
	
	if(*front==(*(rear)+1)%size) {
		printf("\nDequeue is full");
		return;
	}
	if(*front==-1) {
		*front = 0;
		*rear = 0;
	}
	else if(*front==0) {
		*front = size - 1;
	}
	else {
		*front = *front - 1;
	}
	a[*front] = value;
	
}

void deleteFront(int a[], int size, int *front, int *rear) {

	if((*(front)-*(rear))==-1) {
		printf("\nDequeue is empty");
		return;
	}
	printf("\nValue to be deleted from front: %d", a[*front]);
	if(*front==*rear) {
		*front==-1;
		*rear==-1;
	}
	else if(*front==size-1) {
		*front = 0;
	}
	else {
		*front = *front + 1;
	}	
}
void insertRear(int a[], int size, int *front, int *rear, int value) {
	if(*front==(*(rear)+1)%size) {
		printf("\nDequeue is full");
		return;
	}
	if(*rear==-1) {
		*front = 0;
		*rear = 0;
	}
	else if(*rear==size-1) {
		*rear = 0;
	}
	else {
		*rear = *rear + 1;
	}
	a[*rear] = value;
}
void deleteRear(int a[], int size, int *front, int *rear) {
	if(*front==-1) {
		printf("\nEmpty dequeue");
		return;
	}
	printf("\nValue to be deleted from rear: %d", a[*rear]);
	if(*front==*rear) {
		*front = -1;
		*rear = -1;
	}
	else if(*rear==0) {
		*rear = size- 1;
	}
	else {
		*rear = *rear - 1;
	}
}
void display(int a[], int size, int *front, int *rear) {
	if(*front==-1) {
		printf("\nDequeue is empty");
	}
	printf("\nDequeue elements are: ");
	int i=*front;
	do {
		printf("%d\n", a[i]);
		if(i==*rear) {
			break;
		}
		i = (i+1) % size;
	} while(1);
}
void main() {
	int size;
	printf("\nEnter size of the array: ");
	scanf("%d", &size);
	int a[size], front=-1, rear=-1, value, choice;
	while(1){
		printf("\nEnter 1 for insertion at front, 2 for deletion at front, 3 for insertion at rear, 4 for deletion at rear, 5 for display, 6 for exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\nEnter value to be inserted at front: ");
				scanf("%d", &value);
				insertFront(a, size, &front, &rear, value);
				break;
			case 2:
				deleteFront(a, size, &front, &rear);
				break;
			case 3:
				printf("\nEnter value to be inserted at rear: ");
				scanf("%d", &value);
				insertRear(a, size, &front, &rear, value);
				break;
			case 4:
				deleteRear(a, size, &front, &rear);
				break;
			case 5:
				display(a, size, &front, &rear);
				break;
			case 6:
				printf("\nExiting.....");
				exit(0);
		}
	}
}
				
				
