#include<stdio.h>
void main() {
	int n;
	printf("\nEnter number of elements inside the array: ");
	scanf("%d", &n);
	int i, a[n], j, k;
	printf("\nEnter elements of the array: ");
	for(i=0;i<n;i++) {
		scanf("%d", &a[i]);
	}
	for(i=0; i<n; i++) {
		for(j=i;j<n-1;j++) {
			if(a[i] == a[j+1]) {
				for(k=i;k<n;k++) {
					a[k] = a[k+1];
				}
			}
		}
	}
	printf("\nArray after deleting repeated elements: ");
	for(i=0;i<n;i++) {
		printf("%d", a[i]);
	}
}
	
