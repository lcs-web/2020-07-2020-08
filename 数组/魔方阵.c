编写程序，实现如下表所示的5-魔方阵。
17 24 1 8 15
23 5 7 14 16
4 6 13 20 22
10 12 19 21 3
11 18 25 2 9
n-魔方阵：指的是使用1〜n2共n2个自然数排列成一个n×n的方阵，其中n为奇数；该方阵的每行、每列及对角线元素之和都相等，并为一个只与n有关的常数，该常数为n×(n2+1)/2

二维数组解法
#include<stdio.h>
#define N 5
int main()
{
    int a[N][N]={0}, i, j, k, t, x, y;
    i=0;  /*自然数1的行标*/
    j=N/2;  /*自然数1的列标*/
    t=N-1;  /*最后一行、最后一列的下标*/
    for(k=1; k<=N*N; k++)
    {
        a[i][j]=k;
        x=i;
        y=j;
        if(i == 0)
            i=t;
        else
            i=i-1;
        if(j != t)
            j=j+1;
        else
            j=0;
        if(a[i][j]!=0)
        {
            i=x+1;
            j=y;
        }
    }
    printf("生成的5-魔方阵为：");
    for(i=0; i<N; i++)
    {
        printf("\n");
        for(j=0; j<N; j++)
        {
            printf("%3d", a[i][j]);
        }
    }
    printf("\n");
    return 0;
}
