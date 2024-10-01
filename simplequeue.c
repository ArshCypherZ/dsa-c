#include<stdio.h>
#include<stdlib.h>
void enqueue(int a[], int n, int *front, int *rear) {
	if(*rear==n-1) {
		printf("\nQueue is already full");
		exit(0);
	}
	printf("\nEnter value to be inserted: ");
	int x;
	scanf("\n%d", &x);
	if(*rear==-1) {
		*rear = 0;
		*front = 0;
		a[*rear] = x;
	}
	else {
		*rear = *rear + 1;
		a[*rear] = x;
	}
}
void dequeue(int a[], int *front,int *rear) {
	if(*front==-1) {
		printf("\nQueue is already empty");
		exit(0);
	}
	if(*front == *rear) {
		*front =-1;
		*rear = -1;
		return;
	}
	else {
		printf("\nElement to be deleted: %d", a[*front]);
		*front = *front + 1;
	}
}
void traverse(int a[], int *front, int *rear) {
	if(*front==-1) {
		printf("\nQueue is empty");
		exit(0);
	}
	int i;
	for(i=*(front); i<=*(rear); i++) {
		printf("\n%d", a[i]);
	}
}
void main() {
	int choice, n;
	printf("\nEnter the size of the array: ");
	scanf("\n%d", &n);
	int a[n], front=-1, rear=-1;
	
	do {
		printf("\nEnter 1 for insertion, 2 for deletion, 3 for display: ");
		scanf("\n%d", &choice);
		switch(choice) {
			case 1:
				enqueue(a, n, &front, &rear);
				break;
			case 2:
			 	dequeue(a, &front, &rear);
			 	break;
			case 3:
				traverse(a, &front, &rear);
				break;
			default:
				exit(0);
		} 
	} while(1);
}

