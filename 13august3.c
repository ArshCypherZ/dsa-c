#include<stdio.h>
void main() {
	int n;
	printf("\nEnter the size of the array: ");
	scanf("%d", &n);
	int a[n], i, j;
	printf("\nEnter the elements of the array: ");
	for(i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	int temp;
	for(i=0, j=n-1; i<n/2; i++, j--) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	printf("\nArray after reverse is: ");
	for(i=0;i<n;i++) {
		printf("%d", a[i]);
	}
}
