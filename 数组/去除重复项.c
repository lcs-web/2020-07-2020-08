给定一个顺序数组a，删去其中的重复项，并输出。


#include<stdio.h>
int main()
{	
	int a[20];
	int i,j,n,k;
	k=0;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++)
	{
		
		if(a[i]!=a[n-1])
		{
		
		for(j=i+1;j<n;j++)
		{
			
			if(a[j]!=a[i])
			{
				a[i+1]=a[j];
			
				k++;

				break;
			}
		}
		}
	}

	for(i=0;i<k;i++)
	{
		printf("%d\t",a[i]);

	}
	
	return 0;
}
