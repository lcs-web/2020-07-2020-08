海伦公式
1.p=(a+b+c)/2;
2.面积=根号下 p*(p-a)*(p-b)*(p-c)；
引用‘math.h’头文件是要用‘sqrt’这个平方根函数

#include<stdio.h>

#include<math.h>

int main(){

 

    double a,b,c,p,res;

 

    scanf("%lf%lf%lf",&a,&b,&c);

    

    p=(a+b+c)/2;

    

    res = sqrt( p*(p-a)*(p-b)*(p-c) );

 

    printf("%.2f",res);

 

    return 0;

}
