给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

#include<stdio.h>
int main()
{	
	int nums[20];
	int i,j,n,target;
	
	scanf("%d",&n);
	scanf("%d",&target);

	for(i=0;i<n;i++)
	{
		scanf("%d",&nums[i]);
	}

    for (i=0;i<n-1;i++)
    {
        for(j=1;j<n;j++)
        {
            if(nums[i]+nums[j]==target)
            {
              printf("%d %d\n",i,j);
            }
        }
    }
	return 0;
}
