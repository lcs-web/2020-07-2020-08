小区便利店正在促销，用  numBottles个空酒瓶可以兑换一瓶新酒。你购入了 numExchange 瓶酒。

如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。

请你计算 最多 能喝到多少瓶酒。
 
int numWaterBottles(int numBottles, int numExchange)
{
    int num = numBottles;
    int left;
    while (1)
 {
        left = numBottles % numExchange;
        numBottles /= numExchange;
        if (numBottles == 0) break;
        num += numBottles;
        numBottles += left;
    }

    return num;
}
