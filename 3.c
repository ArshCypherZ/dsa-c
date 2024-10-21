#include<stdio.h>
int main()
{
	int n;
	printf("Enter number of terms : ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("enter %d element : ",i+1);
		scanf("%d",&a[i]);
	}
	for(int i=0, j=n-1;i<j;i++,j--)
	{
		int t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	for(int i=0;i<n;i++)
	printf("%d " ,a[i]);
}

	
