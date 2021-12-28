#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


	//字符

	/*char ch[] = "w4545454";
	char *pc = ch;
	printf("%s\n", ch);
	printf("%s\n", pc);*/


	///错误

	/*char *ch = 'wew';
	*ch = 'W';
	printf("%s", ch);*/


	/*char arr1[] = "dasff";
	char arr2[] = "dasff";
const	char * p1 = "dasff";
const	char * p2 = "dasff";
const 	char * p3 = "dasff";

	if (p2 == p1 )
	{
		printf("hehe\n");
	}
	else
	{
		printf("haha\n");
	}*/

	//数组指针
	/*int arr[10] = { 1,23,4,5,6,7,8,9,6,8};
	int *p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}
*/
//二维数组
void  print1 (int arr[3][5], int x, int y)
{
		int i = 0;
		int j = 0;
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				printf("%d", arr[i][j]);
			}	printf("\n");
		}
	
	}
int main()
{
	int arr[3][5] = {{ 1,5,4,4,4 }, { 1,5,4,4,4 }, { 1, 5, 4, 4, 4 }
};
	print1(arr, 3, 5);

	return 0;
}