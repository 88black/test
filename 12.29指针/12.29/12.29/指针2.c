#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
///ʵ��ð������
//void buble_sort(void *base, int sz, int width,int (*cmp)(void *e1 , void *e2))
//{
//	int i = 0;
//	//һ��
//	for (i = 0; i < sz - 1; i++)
//	{
//		//�Ƚ�ÿһ�δ�С
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//����Ԫ�رȽ�ͨ��
//			if (cmp((char*)base+j*width ,(char *)base+(j+1)*width) > 0 )   //����Ԫ��
//			{
//				Swap((char*)base + j * width, (char *)base + (j + 1)*width);
//			}
//		}
//	}
//}
//void test()
//{
//	int arr[10] = { 9,5,7,6,5,9,1,6,5,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	buble_sort(arr,sz ,sizeof(arr[0]),);
//}
//int main()
//{
//	test();
//	return 0;
//}
