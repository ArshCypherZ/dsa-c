#include<stdio.h>
#include<stdlib.h>
void push(int a[],int *top, int N) {
	if(*top==N-1) {
		printf("Stack is full");
		exit(0);
	}
	int x;
	printf("\nEnter value to be pushed: ");
	scanf("%d", &x);
	(*top)++;
	a[*top]=x;
}
void pop(int a[], int *top) {
	if(*top==-1) {
		printf("Stack is empty");
		exit(0);
	}
	int x=a[*top];
	(*top)--;
}
void display(int a[], int *top) {
	if(*top==-1) {
		printf("Stack is empty");
		exit(0);
	}
	int temp = *top;
	while(temp!=-1) {
		printf("%d", a[temp]);
		temp--;
	}
}
void main() {
	int top=-1, N, choice;
	printf("\nEnter size of the array: ");
	scanf("%d", &N);
	int a[N];
	do{
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				push(a, &top, N);
				break;
			case 2:
				pop(a,&top);
				break;
			case 3:
				display(a,&top);
				break;
			default:
				exit(0);
		}
	}while(1);
}
	
