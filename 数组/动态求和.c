给你一个数组 nums ,把数组 nums 的动态和放在数组runningsum中(runningsum[i] = nums[0]+...+nums[i])

#include<stdio.h>
int main()
{
	int nums[5];
	int runningsum[5];
	int i,j,n;
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&nums[i]);
	}
	for(i=0;i<5;i++)
	{
		n=0;

		for(j=0;j<=i;j++)
		{
			n+=nums[j];
		}
		runningsum[i]=n;
	}

	for(i=0;i<5;i++)
	{
		printf("%d\t",runningsum[i]);
	}

	return 0;
}
