#include<stdio.h>
void enqueue(int A, int MAX, int *front, int *rear) {
	int x;
	scanf("%d", &x);
	if(*(front)==((*(rear)+1)%MAX)) {
		printf("Queue is full");
		return;
	}
	else if(*(rear)==-1) {
		*rear = 0;
		*front = 0;
	}
	else {
		*rear = *rear + (*(rear)+1)%MAX;
		A[*rear] = x;
	}
}
void dequeue(int A, int MAX, int *front, int *rear) {
	if(*(front)==-1) {
		printf("\nQueue is already empty");
		return;
	}
	else if(*(front)==*(rear)) {
		printf("%d", A[*front]);
		*front = -1;
		*rear = -1;
		return;
	}
	else {
		printf("%d", A[*front]);
		*front = *front + (front+1)%MAX;
	}
}
void traverse(int A, int MAX, int *front, int *rear) {
	if(*(front)==-1) {
		printf("\nQueue is empty");
		return;
	}
	int i;
	for(i=*(front); i<=*(rear);(i+1)%max) {
		printf("%d", A[i]);
	}
}
void main() {
	int choice, MAX;
	printf("\nEnter the size of the array: ");
	scanf("%d", &MAX);
	int A[MAX];
	do {
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				enqueue(A, 
	
	
