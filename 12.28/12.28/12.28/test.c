#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//void test(int arr[3][5])//0k
//{
//
//}
//void test1(int arr[][5]) //0k
//{
//}
//void test3(int *arr)//error
//{
//
//}
//void test4(int **arr)
//{
//}
//void test5(int (*arr)[5])
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	int test(arr);//二维数组传参
//
//	return 0;
//}


////函数指针
//void Print(char*str)
//{
//	printf("%s", str);
//}
//int main()
//{
//	void(*p)(char*) = Print;
//	(*p)("hello  world");
//	return 0;
//}


//void(* signal(int, void(*)(int)))(int);
//typedef void(*)(int);
//int	Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	//指针数组
//	int *arr [5];
//	int(*pa)(int, int) = Add;
//	printf("%d", pa(2,3));
//	return 0;
//}

////计算器

//void menu()
//{
//	printf("************************************\n");
//	printf("**********1.add       2.sub**************************\n");
//	printf("**********3.mul*******4.div*******************\n");
//
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int y = 0;
//	int x = 0;
//	int input = 0;
//	int(*pfArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		printf("输入两个值:>");
//		if (input >= 1 && input <= 4  )
//		{
//			printf("输入两个值:>");
//
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出");
//		}
//		else
//		{
//			printf("选择错误\n");
//
//		}
//
//		/*switch (input)
//		{
//		case 1:
//			printf("请输入两个数");
//			printf("%d\n", Add (x,y));
//			break;
//		case 2:
//			printf("请输入两个数");
//
//			printf("%d\n", Sub(x,y));
//			break;
//		case 3:
//			printf("请输入两个数");
//
//			printf("%d\n", Mul(x,y));
//			break;
//		case 4:
//			printf("请输入两个数");
//
//			printf("%d\n", Div(x,y));
//			break;
//		case 0:
//			printf("退出");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//*/
/*	}*/
//	} while (input);
//	return 0;
//}
int Add(int x, int y)
{
	return x + y;

}
int main()
{
	int arr[10] = { 0 };
	int(*p)[10] = &arr;//数组指针
	int(*pfArr[4])(int, int);///函数指针数组
	int(*(*ppfArr)[4])(int, int) = &pfArr;///指针数组
	//////指向数组每个元素类型是int (*)(int ,int )
	return 0;

}