#include<stdio.h>
#include<stdlib.h>
void main() {
	int size;
	printf("\nEnter the size of the array: ");
	scanf("%d", &size);
	int *p, i, k;
	p = (int *)malloc(size*sizeof(int));
	printf("\nEnter the elements of the array: ");
	for(i=0;i<size;i++) {
		scanf("%d", (p+i));
	}
	printf("\nEnter the element to search: ");
	scanf("%d", &k);
	for(i=0;i<size;i++) {
		if(*(p+i)==k) {
			printf("\nElement found at %dth index", i);
			exit(0);
		}
	}
	printf("\nElement not found");
}
	
	
