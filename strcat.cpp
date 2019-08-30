#define _CRT_SECURE_NO_WARNINGS 1
#include "stdio.h"
#include "windows.h"
#include "string.h"
char* My_strcat( char* dst,char* src)
{
	 char* start = dst;
	while (*++dst);//先让dst到达末尾
	do
	{
	  *dst++ = *src++;
	} while (*src);
	return start;
}
int main(void)
{
	char p[] = "i'm a good boy";
	char a[40] = "Hello,";//要保证目标串足够长
                My_strcat(a,p);
	printf("%s\n", a);
	system("pause");
	return 0;
}