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
	while (*dst)//������û�ߵ���β
	{
		const char start = dst;//�鵽������λ��,�������棬��ƥ��ʱ����ʹ��

		while (*dst == *tag && *tag != '\0')//���ҵ��ִ�����ƥ��ʱ�������ж��Ƿ���ȫƥ��
		{
			dst++;//
			tag++;
		}
		if (*tag == '\0')//��ȫƥ��  �Ӵ�ָ�뵽�˽�β��˵���鵽����
		{
			return start;//���ز��ҵ�ƥ���λ��
		}
		else//����˵�������˲���ȫƥ��
		{
			start++;	//����ָ�����
			src = tag;
		}
			dst++;//����ָ�������
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