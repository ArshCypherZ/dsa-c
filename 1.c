#include<stdio.h>
int main()
{
	int n;
	int odd=0,even=0;
	printf("Enter number of terms : ");
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter %d element : ",i+1);
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		even++;
		else
		odd++;
	}
	printf("even numbers : %d\nodd numbers : %d",even,odd);
	return 0;
}
