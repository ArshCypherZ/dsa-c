#include<stdio.h>
#include<stdlib.h>
int priority(int num) {
	if(num%2==0)
		return 1;
	else
		return 0;
}
int sort(int item, int array[], int i) {
	while(priority(array[i])<priority(item) && i!=-1) {
			array[i+1] = array[i];
			i--;
	}
	return (i+1);
}
void enqueue(int array[], int size, int *front, int *rear) {
	if(*front == (*(rear)+1) % size) {
		printf("\nQueue overflowed :( ");
	}
	else {
		int item;
		printf("\nEnter the item to be inserted: ");
		scanf("%d", &item);
		if(*rear == -1) {
			*front = 0;
			*rear = 0;
			array[*rear] = item;
		} else {
			*rear = (*rear+1)%size;
			if(priority(item > priority(array[*rear-1]))) {
				int index = sort(item, array, *(rear)-1);
				array[index] = item;
			}
			else {
				array[*rear] = item;
			}
		}
	}
}
void dequeue(int *front, int *rear, int max) {
	if(*front==-1) {
		printf("\nQueue underflow");
	}
	else {
		if(*front==*rear) {
			*front = -1;
			*rear = -1;
		}
		else {
			*front = (*front+1)%max;
			}
	}
}
void display(int *rear, int *front, int max, int queue[]) {
	int i;
	if(*front==-1) {
	printf("\nQueue empty");
	}
	for(i=*front; i!=*rear; i=(i+1)%max) {
		printf("%d", queue[i]);
	}
	printf("%d", queue[*rear]);
}
	
	
void main() {
	int size;
	printf("\nEnter size of the queue: ");
	scanf("%d", &size);
	int array[size], front=-1, rear=-1, i, choice;
	while(1) {
		printf("\nEnter 1 for enqueue, 2 for dequeue, 3 for traverse, 4 for exit");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				enqueue(array, size, &front, &rear);
				break;
			case 2:
				dequeue(&front, &rear, size);
				break;
			case 3:
				display(&rear, &front, size, array);
				break;
			case 4:
				printf("\nExiting....");
				exit(1);
			default:
				printf("\nWrong choice.");
		}
	}
}
