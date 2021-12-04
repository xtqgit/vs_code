/*#include <stdio.h>
int main()
{
char str1[] = "hello bit.";
char str2[] = "hello bit.";
const char *str3 = "hello bit.";
const char *str4 = "hello bit.";
if(str1 == str2)
	printf("str1 and str2 are same\n");
else
	printf("str1 and str2 are not same\n");

if(str3 == str4)
	printf("str3 and str4 are same\n");
else
	printf("str3 and str4 are not same\n");
return 0; 
}*/

/*#include <stdio.h>
int main()
{
    int arr[10] = {0};
    printf("%p\n", arr);
    printf("%p\n", &arr);
    return 0; 
}*/

/*#include <stdio.h>
int main()
{
    int arr[10] = { 0 };
    printf("arr = %p\n", arr);
    printf("&arr= %p\n", &arr);
    printf("arr+1 = %p\n", arr+1);
    printf("&arr+1= %p\n", &arr+1);
    return 0; 
 }*/

 /*#include <stdio.h>

void print_arr1(int arr[3][5], int row, int col) 
{
    int i = 0,j = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}
void print_arr2(int (*arr)[5], int row, int col) 
{
    int i = 0,j = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}
int main()
{
    int arr[3][5] = {1,2,3,4,5,6,7,8,9,10};
    print_arr1(arr, 3, 5);
    //数组名arr，表示首元素的地址
    //但是二维数组的首元素是二维数组的第一行
    //所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
    //可以数组指针来接收
    print_arr2(arr, 3, 5);
    return 0; 
}*/

/*void test(int arr[3][5])//ok？
{}
//void test(int arr[][])//ok？错误
//{}
void test2(int arr[][5])//ok？
{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//这样才方便运算。
//void test3(int *arr)//ok？
//{}
//void test4(int* arr[5])//ok？
//{}
void test5(int (*arr)[5])//ok？
{}
//void test6(int **arr)//ok？
//{}
int main()
{
 int arr[3][5] = {0};
 test5(arr);
}*/

/*#include <stdio.h>
void test()
{
    printf("hehe\n");
}
    int main()
{
    printf("%p\n", test);
    printf("%p\n", &test);
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    //一维数组
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));       //sizeof(数组名)-计算的是数组总大小-单位是字节-16;
    printf("%d\n",sizeof(a+0));     //4/8-数组名这里表示首元素的地址，a+0还是首元素地址，地址大小是4/8个字节;
    printf("%d\n",sizeof(*a));      //4-数组名表示首元素地址，*a就是首元素，sizeof(*a)就是4;
    printf("%d\n",sizeof(a+1));     //4/8-数组名这里表示首元素的地址，a+1表示第二个元素的地址，地址的大小就是4/8个字节;
    printf("%d\n",sizeof(a[1]));    //4-第二个元素的大小;
    printf("%d\n",sizeof(&a));      //4/8-&a取出的是数组的地址，但是数组的地址也还是地址，地址的大小就是4/8个字节;
    printf("%d\n",sizeof(*&a));     //16-&a数组的地址，数组的地址解引用访问的数组，sizeof计算的就是数组的大小;
    printf("%d\n",sizeof(&a+1));    //4/8-&a数组的地址，&a+1虽然地址跳过整个数组，但还是地址，所以是4/8个字节;
    printf("%d\n",sizeof(&a[0]));   //4/8 &a[0]是第一个元素的地址;
    printf("%d\n",sizeof(&a[0]+1)); //4/8 &a[0]+1是第二个元素的地址;
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    //字符数组
    char arr[] = {'a','b','c','d','e','f'};
    printf("%d\n", sizeof(arr));        //6,sizeof计算的是数组大小;
    printf("%d\n", sizeof(arr+0));      //4/8 arr是首元素地址，arr+0还是首元素地址，地址的大小是4/8字节;
    printf("%d\n", sizeof(*arr));       //1 arr是首元素的地址，*arr是首元素，首元素是字符大小;
    printf("%d\n", sizeof(arr[1]));     //1
    printf("%d\n", sizeof(&arr));       //4/8 &arr虽然是数组地址，但还是地址，地址大小位4/8字节;
    printf("%d\n", sizeof(&arr+1));     //4/8 &arr+1是跳过整个数组的地址，地址大小是4/8字节;
    printf("%d\n", sizeof(&arr[0]+1));  //4/8 &arr[0]+1表示第二个元素的地址;
    printf("\n");
    printf("%d\n", strlen(arr));        //随机值,strlen是计算字符串从起始到'\0'结束，不包括'\0'的大小，单位字节;
    printf("%d\n", strlen(arr+0));      //随机值
    //printf("%d\n", strlen(*arr));       //错误写法,strlen函数的参数只能接收地址;
    //printf("%d\n", strlen(arr[1]));     //错误写法
    printf("%d\n", strlen(&arr));       //随机值
    printf("%d\n", strlen(&arr+1));     //随机值-6
    printf("%d\n", strlen(&arr[0]+1));  //随机值-1
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    char arr[] = "abcdef";
    printf("%d\n", sizeof(arr));        //7   sizeof(arr)计算的是数组总大小-单位是字节;
    printf("%d\n", sizeof(arr+0));      //4/8 计算的是地址的大小-arr+0是首元素的地址;
    printf("%d\n", sizeof(*arr));       //1   *arr是首元素，sizeof(*arr)计算首元素的大小;
    printf("%d\n", sizeof(arr[1]));     //1   arr[1]是第二个元素,sizeof(arr[1])计算的是第二个元素的大小;
    printf("%d\n", sizeof(&arr));       //4/8 &arr虽然是数组地址,但还是地址;
    printf("%d\n", sizeof(&arr+1));     //4/8 &arr+1是跳过整个数组后的地址，但也是地址;
    printf("%d\n", sizeof(&arr[0]+1));  //4/8 &arr[0]+1第二个元素的地址;
    printf("\n");
    printf("%d\n", strlen(arr));        //6
    printf("%d\n", strlen(arr+0));      //6
    //printf("%d\n", strlen(*arr));     //eir
    //printf("%d\n", strlen(arr[1]));   //eir
    printf("%d\n", strlen(&arr));       //6 &arr - 数组的地址- 数组指针 char(*p)[7] = &arr;
    printf("%d\n", strlen(&arr+1));     //随机值
    printf("%d\n", strlen(&arr[0]+1));  //5
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    char *p = "abcdef";
    printf("%d\n", sizeof(p));      //4/8 - 计算指针变量p的大小;
    printf("%d\n", sizeof(p+1));    //4/8 - p+1得到的是字符b的地址;
    printf("%d\n", sizeof(*p));     //1   - *p就是字符串的第一个字符 - 'a'
    printf("%d\n", sizeof(p[0]));   //1   - int arr[10];arr[0] == *(arr+0) p[0]==*(p+0)=='a'
    printf("%d\n", sizeof(&p));     //4/8
    printf("%d\n", sizeof(&p+1));   //4/8
    printf("%d\n", sizeof(&p[0]+1));//4/8
    printf("\n");
    printf("%d\n", strlen(p));      //6
    printf("%d\n", strlen(p+1));    //5
    //printf("%d\n", strlen(*p));   //eir
    //printf("%d\n", strlen(p[0])); //eir
    printf("%d\n", strlen(&p));     //随机值
    printf("%d\n", strlen(&p+1));   //随机值
    printf("%d\n", strlen(&p[0]+1));//5
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    int a[3][4] = {0};
    printf("%d\n",sizeof(a));           //48
    printf("%d\n",sizeof(a[0][0]));     //4
    printf("%d\n",sizeof(a[0]));        //16 a[0]相当于第一行作为一维数组的数组名;
    //sizeof(arr[0])把数组名单独放在sizeof()内，计算的是第一行的大小;
    printf("%d\n",sizeof(a[0]+1));      //4/8 a[0]是第一行的数组名，数组名此时是首元素地址，a[0]其实就是第一行第一个元素的地址;
    //所以a[0]+1就是第一行第二个元素的地址- 地址的大小是4/8字节;
    printf("%d\n",sizeof(*(a[0]+1)));   //4   *(a[0]+1)是第一行第二个元素，大小是4个字节;
    printf("%d\n",sizeof(a+1));         //4/8 a是二维数组的数组名，没有sizeof(a)，也没有&a，所以a是首元素地址;
    //而把二维数组看成一堆数组时，二维数组的首元素是他的第一行，a就是第一行（首元素）的地址;a+1就是第二行地址;
    //二维数组看成一维数组时，二维数组的一行相当于一维数组的一个元素，所以第二个元素就表示第二行的元素;
    printf("%d\n",sizeof(*(a+1)));      //16  sizeof(a[1])计算第二行的大小,单位是字节;
    printf("%d\n",sizeof(&a[0]+1));     //4/8 第二行的地址;
    printf("%d\n",sizeof(*(&a[0]+1)));  //16  计算第二行的大小，单位是地址;
    printf("%d\n",sizeof(*a));          //16  a是首元素地址-第一行的地址，*a就是第一行,sizeof(*a)就是计算第一行的大小;
    printf("%d\n",sizeof(a[3]));        //16  sizeof()并不会对内部的表达式进行计算，此处a[3]表示数组a的第四行元素所占空间大小;
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    int a[5] = { 1, 2, 3, 4, 5 };
    int *ptr = (int *)(&a + 1);
    printf( "%d,%d", *(a + 1), *(ptr - 1));
    return 0; 
}*/
//程序的结果是什么？

/*#include <stdio.h>
//由于还没学习结构体，这里告知结构体的大小是20个字节
struct Test
{
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}* p;
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//已知，结构体Test类型的变量大小是20个字节
int main()
{
    p = (struct Test*)0x100000;
    printf("%p\n", p + 0x1);
    printf("%p\n", (unsigned long)p + 0x1);
    printf("%p\n", (unsigned int*)p + 0x1);
    return 0; 
 }*/

 /*#include <stdio.h>
 int main()
{
    int a[4] = { 1, 2, 3, 4 };
    int *ptr1 = (int *)(&a + 1);
    int *ptr2 = (int *)((int)a + 1);
    printf( "%x,%x", ptr1[-1], *ptr2);
    return 0; 
}*/

/*#include <stdio.h>
int main()
{
    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
    int *p;
    p = a[0];
    printf( "%d", p[0]);
    return 0; 
 }*/

/*#include <stdio.h>
 int main()
{
    int a[5][5];
    int(*p)[4];
    p = a;
    printf( "%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int *ptr1 = (int *)(&aa + 1);
    int *ptr2 = (int *)(*(aa + 1));
    printf( "%d,%d", *(ptr1 - 1), *(ptr2 - 1));
    return 0; 
 }*/

/*#include <stdio.h>
int main()
{
    char *a[] = {"work","at","alibaba"};
    char**pa = a;
    pa++;
    printf("%s\n", *pa);
    return 0; 
 }*/

#include <stdio.h>
 int main()
{
    char *c[] = {"ENTER","NEW","POINT","FIRST"};
    char**cp[] = {c+3,c+2,c+1,c};
    char***cpp = cp;
    printf("%s\n", **++cpp);
    printf("%s\n", *--*++cpp+3);
    printf("%s\n", *cpp[-2]+3);
    printf("%s\n", cpp[-1][-1]+1);
    return 0;
}