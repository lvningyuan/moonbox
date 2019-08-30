#define _CRT_SECURE_NO_WARNINGS 1
#include"stdio.h"
#include "windows.h"
//int main ()
//{
//	char str[] = "this,a simple string.";
//	char * pch;
//	printf("%s\n",str);
//	pch= strtok(str," ,.-");
//		while (pch != NULL)
//		{
//		printf("%s\n", pch);
//		pch=strtok(NULL," ,.-");//
//		}
//	printf("%s\n",str);
//
// system("pause");
//	 return 0;
//}
char* My_strstr(const char* dst, const char* tag)
{
	const char *  src = tag;
	while (*dst)//当父串没走到结尾
	{
		const char start = dst;//查到父串的位置,作个保存，不匹配时返回使用

		while (*dst == *tag && *tag != '\0')//当找到字串存在匹配时，接着判断是否完全匹配
		{
			dst++;//
			tag++;
		}
		if (*tag == '\0')//完全匹配  子串指针到了结尾，说明查到存在
		{
			return start;//返回查找到匹配的位置
		}
		else//否则说明，该趟不完全匹配
		{
			start++;	//父串指针后移
			src = tag;
		}
			dst++;//父串指针向后移
	}
	return NULL;
}
int main(void)
{
	char *p1 = "as long as you love me";
	char p2[] = "you";
	
	printf("%s",My_strstr(p1,p2));
	system("pause");
	return 0;
}