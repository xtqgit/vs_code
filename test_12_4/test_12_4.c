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
    //������arr����ʾ��Ԫ�صĵ�ַ
    //���Ƕ�ά�������Ԫ���Ƕ�ά����ĵ�һ��
    //�������ﴫ�ݵ�arr����ʵ�൱�ڵ�һ�еĵ�ַ����һά����ĵ�ַ
    //��������ָ��������
    print_arr2(arr, 3, 5);
    return 0; 
}*/

/*void test(int arr[3][5])//ok��
{}
//void test(int arr[][])//ok������
//{}
void test2(int arr[][5])//ok��
{}
//�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
//��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
//�����ŷ������㡣
//void test3(int *arr)//ok��
//{}
//void test4(int* arr[5])//ok��
//{}
void test5(int (*arr)[5])//ok��
{}
//void test6(int **arr)//ok��
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
    //һά����
    int a[] = {1,2,3,4};
    printf("%d\n",sizeof(a));       //sizeof(������)-������������ܴ�С-��λ���ֽ�-16;
    printf("%d\n",sizeof(a+0));     //4/8-�����������ʾ��Ԫ�صĵ�ַ��a+0������Ԫ�ص�ַ����ַ��С��4/8���ֽ�;
    printf("%d\n",sizeof(*a));      //4-��������ʾ��Ԫ�ص�ַ��*a������Ԫ�أ�sizeof(*a)����4;
    printf("%d\n",sizeof(a+1));     //4/8-�����������ʾ��Ԫ�صĵ�ַ��a+1��ʾ�ڶ���Ԫ�صĵ�ַ����ַ�Ĵ�С����4/8���ֽ�;
    printf("%d\n",sizeof(a[1]));    //4-�ڶ���Ԫ�صĴ�С;
    printf("%d\n",sizeof(&a));      //4/8-&aȡ����������ĵ�ַ����������ĵ�ַҲ���ǵ�ַ����ַ�Ĵ�С����4/8���ֽ�;
    printf("%d\n",sizeof(*&a));     //16-&a����ĵ�ַ������ĵ�ַ�����÷��ʵ����飬sizeof����ľ�������Ĵ�С;
    printf("%d\n",sizeof(&a+1));    //4/8-&a����ĵ�ַ��&a+1��Ȼ��ַ�����������飬�����ǵ�ַ��������4/8���ֽ�;
    printf("%d\n",sizeof(&a[0]));   //4/8 &a[0]�ǵ�һ��Ԫ�صĵ�ַ;
    printf("%d\n",sizeof(&a[0]+1)); //4/8 &a[0]+1�ǵڶ���Ԫ�صĵ�ַ;
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    //�ַ�����
    char arr[] = {'a','b','c','d','e','f'};
    printf("%d\n", sizeof(arr));        //6,sizeof������������С;
    printf("%d\n", sizeof(arr+0));      //4/8 arr����Ԫ�ص�ַ��arr+0������Ԫ�ص�ַ����ַ�Ĵ�С��4/8�ֽ�;
    printf("%d\n", sizeof(*arr));       //1 arr����Ԫ�صĵ�ַ��*arr����Ԫ�أ���Ԫ�����ַ���С;
    printf("%d\n", sizeof(arr[1]));     //1
    printf("%d\n", sizeof(&arr));       //4/8 &arr��Ȼ�������ַ�������ǵ�ַ����ַ��Сλ4/8�ֽ�;
    printf("%d\n", sizeof(&arr+1));     //4/8 &arr+1��������������ĵ�ַ����ַ��С��4/8�ֽ�;
    printf("%d\n", sizeof(&arr[0]+1));  //4/8 &arr[0]+1��ʾ�ڶ���Ԫ�صĵ�ַ;
    printf("\n");
    printf("%d\n", strlen(arr));        //���ֵ,strlen�Ǽ����ַ�������ʼ��'\0'������������'\0'�Ĵ�С����λ�ֽ�;
    printf("%d\n", strlen(arr+0));      //���ֵ
    //printf("%d\n", strlen(*arr));       //����д��,strlen�����Ĳ���ֻ�ܽ��յ�ַ;
    //printf("%d\n", strlen(arr[1]));     //����д��
    printf("%d\n", strlen(&arr));       //���ֵ
    printf("%d\n", strlen(&arr+1));     //���ֵ-6
    printf("%d\n", strlen(&arr[0]+1));  //���ֵ-1
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    char arr[] = "abcdef";
    printf("%d\n", sizeof(arr));        //7   sizeof(arr)������������ܴ�С-��λ���ֽ�;
    printf("%d\n", sizeof(arr+0));      //4/8 ������ǵ�ַ�Ĵ�С-arr+0����Ԫ�صĵ�ַ;
    printf("%d\n", sizeof(*arr));       //1   *arr����Ԫ�أ�sizeof(*arr)������Ԫ�صĴ�С;
    printf("%d\n", sizeof(arr[1]));     //1   arr[1]�ǵڶ���Ԫ��,sizeof(arr[1])������ǵڶ���Ԫ�صĴ�С;
    printf("%d\n", sizeof(&arr));       //4/8 &arr��Ȼ�������ַ,�����ǵ�ַ;
    printf("%d\n", sizeof(&arr+1));     //4/8 &arr+1���������������ĵ�ַ����Ҳ�ǵ�ַ;
    printf("%d\n", sizeof(&arr[0]+1));  //4/8 &arr[0]+1�ڶ���Ԫ�صĵ�ַ;
    printf("\n");
    printf("%d\n", strlen(arr));        //6
    printf("%d\n", strlen(arr+0));      //6
    //printf("%d\n", strlen(*arr));     //eir
    //printf("%d\n", strlen(arr[1]));   //eir
    printf("%d\n", strlen(&arr));       //6 &arr - ����ĵ�ַ- ����ָ�� char(*p)[7] = &arr;
    printf("%d\n", strlen(&arr+1));     //���ֵ
    printf("%d\n", strlen(&arr[0]+1));  //5
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    char *p = "abcdef";
    printf("%d\n", sizeof(p));      //4/8 - ����ָ�����p�Ĵ�С;
    printf("%d\n", sizeof(p+1));    //4/8 - p+1�õ������ַ�b�ĵ�ַ;
    printf("%d\n", sizeof(*p));     //1   - *p�����ַ����ĵ�һ���ַ� - 'a'
    printf("%d\n", sizeof(p[0]));   //1   - int arr[10];arr[0] == *(arr+0) p[0]==*(p+0)=='a'
    printf("%d\n", sizeof(&p));     //4/8
    printf("%d\n", sizeof(&p+1));   //4/8
    printf("%d\n", sizeof(&p[0]+1));//4/8
    printf("\n");
    printf("%d\n", strlen(p));      //6
    printf("%d\n", strlen(p+1));    //5
    //printf("%d\n", strlen(*p));   //eir
    //printf("%d\n", strlen(p[0])); //eir
    printf("%d\n", strlen(&p));     //���ֵ
    printf("%d\n", strlen(&p+1));   //���ֵ
    printf("%d\n", strlen(&p[0]+1));//5
    return 0;
}*/

/*#include <stdio.h>
int main()
{
    int a[3][4] = {0};
    printf("%d\n",sizeof(a));           //48
    printf("%d\n",sizeof(a[0][0]));     //4
    printf("%d\n",sizeof(a[0]));        //16 a[0]�൱�ڵ�һ����Ϊһά�����������;
    //sizeof(arr[0])����������������sizeof()�ڣ�������ǵ�һ�еĴ�С;
    printf("%d\n",sizeof(a[0]+1));      //4/8 a[0]�ǵ�һ�е�����������������ʱ����Ԫ�ص�ַ��a[0]��ʵ���ǵ�һ�е�һ��Ԫ�صĵ�ַ;
    //����a[0]+1���ǵ�һ�еڶ���Ԫ�صĵ�ַ- ��ַ�Ĵ�С��4/8�ֽ�;
    printf("%d\n",sizeof(*(a[0]+1)));   //4   *(a[0]+1)�ǵ�һ�еڶ���Ԫ�أ���С��4���ֽ�;
    printf("%d\n",sizeof(a+1));         //4/8 a�Ƕ�ά�������������û��sizeof(a)��Ҳû��&a������a����Ԫ�ص�ַ;
    //���Ѷ�ά���鿴��һ������ʱ����ά�������Ԫ�������ĵ�һ�У�a���ǵ�һ�У���Ԫ�أ��ĵ�ַ;a+1���ǵڶ��е�ַ;
    //��ά���鿴��һά����ʱ����ά�����һ���൱��һά�����һ��Ԫ�أ����Եڶ���Ԫ�ؾͱ�ʾ�ڶ��е�Ԫ��;
    printf("%d\n",sizeof(*(a+1)));      //16  sizeof(a[1])����ڶ��еĴ�С,��λ���ֽ�;
    printf("%d\n",sizeof(&a[0]+1));     //4/8 �ڶ��еĵ�ַ;
    printf("%d\n",sizeof(*(&a[0]+1)));  //16  ����ڶ��еĴ�С����λ�ǵ�ַ;
    printf("%d\n",sizeof(*a));          //16  a����Ԫ�ص�ַ-��һ�еĵ�ַ��*a���ǵ�һ��,sizeof(*a)���Ǽ����һ�еĴ�С;
    printf("%d\n",sizeof(a[3]));        //16  sizeof()��������ڲ��ı��ʽ���м��㣬�˴�a[3]��ʾ����a�ĵ�����Ԫ����ռ�ռ��С;
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
//����Ľ����ʲô��

/*#include <stdio.h>
//���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�
struct Test
{
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}* p;
//����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
//��֪���ṹ��Test���͵ı�����С��20���ֽ�
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