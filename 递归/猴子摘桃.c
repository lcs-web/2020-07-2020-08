猴子第一天摘下N个桃子，当时就吃了一半，还不过瘾，就又多吃了一个。第二天又将剩下的桃子吃掉一半，又多吃了一个。以后每天都吃前一天剩下的一半零一个。到第10天在想吃的时候就剩一个桃子了,问第一天共摘下来多少个桃子？并反向打印每天所剩桃子数。

#include <stdio.h>

int getPeachNumber(n)

{

    int num;    //定义所剩桃子数

    if(n==10)

    {

       return 1;       //递归结束条件

    } 

    else

    {

        num = getPeachNumber(n+1)*2 + 2;   //递归

        printf("第%d天所剩桃子%d个\n", n, num); //天数，所剩桃子个数

    }

    return num;

}

int main()

{

    int num = getPeachNumber(1);

    printf("猴子第一天摘了:%d个桃子。\n", num);

    return 0;

}
