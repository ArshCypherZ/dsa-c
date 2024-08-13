#include<stdio.h>
void main() {
	int m, n;
	printf("\nEnter rows and colums: ");
	scanf("%d%d", &m, &n);
	int a[m][n], b[m][n], i, j, k, c[m][n];
	printf("\nEnter matrix 1: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("\nEnter matrix 2: ");
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			scanf("%d", &b[i][j]);
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			c[i][j] = 0;
			for(k=0; k<m; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	printf("\nMultiplied matrix is: ");
	for(i=0;i<m; i++) {
		for(j=0;j<n;j++) {
			printf("%d", c[i][j]);
		}
	}
}
	
