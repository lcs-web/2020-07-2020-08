不允许创建临时变量求字符串长度，实现strlen的模拟：

#include<stdio.h>

#include<assert.h>

int my_strlen_no(char const *p)

{

	assert(p != NULL);

	if (*p == NULL)

	{

		return 0;

	}

	else

	{

		return (1 + my_strlen_no(p + 1));

	}

}

int main()

{

	char *p = "abcdef";

	printf("长度是：%d\n", my_strlen_no(p));

	system("pause");

	return 0;

}
