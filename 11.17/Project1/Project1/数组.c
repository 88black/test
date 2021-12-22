#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

////int main()
////{
////	printf("hello");
////	return 0;
////}
//
//
////int main()
////{
////	char arr4[] = "advasr";
////	printf("%d\n ", sizeof(arr4));
////	printf("%d\n ", strlen(arr4));
////	return 0;
////}
//
//
////
//
//
//
////二维数组
//
//
//int main()
//{
//	int i = 0;
//	int arr[3][4] = {{ 1,2,3,}, { 3,5 }};
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d",arr[i][j]);
//		}
//	}
//
//}



//三维数组

int main();
{
	 int i = 3;

	*p(i) = 4;
	printf("%p", &i);


	return 0;
}







///冒泡排序
//void bubble_sort(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{	
//		int j = 0;
//		for (j = 0; j <sz-1-i ; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr ,sz);//冒泡排序函数
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}