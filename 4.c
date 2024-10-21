#include<stdio.h>
int main()
{
	int n;
	printf("enter number of terms : ");
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter %d element : ",i+1);
		scanf("%d",&a[i]);
	}
	int d1=a[1]-a[0],d2,m;
	for(i=0;i<n;i++)
	{
		 d2=a[i+1]-a[i];
		if(d1!=d2)
		{
			printf("array not in ap\n");
			break;
		}
	}
	/*if((a[n-2]-a[n-1])!=d1)
	{
		printf("array not in ap");
		return 0;
	}*/
	if(d2!=d1){
	m=a[i]+d1;
	printf("missing term is %d\n",m);}
	else
	printf("array in ap");
	return 0;
}

