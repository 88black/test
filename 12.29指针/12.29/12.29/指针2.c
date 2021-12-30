#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
///实现冒泡排序
//void buble_sort(void *base, int sz, int width,int (*cmp)(void *e1 , void *e2))
//{
//	int i = 0;
//	//一次
//	for (i = 0; i < sz - 1; i++)
//	{
//		//比较每一次大小
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//两个元素比较通用
//			if (cmp((char*)base+j*width ,(char *)base+(j+1)*width) > 0 )   //交换元素
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
