#include <stdio.h>
#include <string.h>

struct stu{
    char name[20];
    int age;
};

//两个整型变量比较大小，返回值为x-y;
int com_int(void* x,void* y)
{
    return *(int*)x - *(int*)y;
}

//两个浮点型变量比较大小，返回值为x-y;
int com_float(void* x,void* y)
{
    return (int)(*(float*)x - *(float*)y);
}

//两个结构体变量比较大小，返回值为x-y;
int com_struct_name(void* x,void* y)
{
    return strcmp(((struct stu*)x)->name,((struct stu*)y)->name);
}

int com_struct_age(void* x,void* y)
{
    return (int)(((struct stu*)x)->age - ((struct stu*)y)->age);
}

//将两个数据进行交换;
void swp(char* e1 , char* e2 , int with)
{
    int i = 0;
    int temp = 0;
    for(i=0;i<with;i++)
    {
        temp = *e1;
        *e1 = *e2;
        *e2 = temp;
        e1++;
        e2++;
    }
}

//冒泡排序算法主体实现；
void com(void* arr,int sz,int with,int (*comper)(void* e1,void* e2))
{
    int i = 0;
    for(i=0;i<sz-1;i++)
    {
        int j = 0;
        for(j=0;j<sz-1-i;j++)
        {
            if((*comper)(((char*)arr) + j*with ,((char*)arr) + (j+1)*with) > 0)//比较arr[j]与arr[j+1]的大小;
            {
                swp(((char*)arr) + j*with,((char*)arr) + (j+1)*with,with);//如果arr[j]大于arr[j+1]，将arr[j]与arr[j+1]的数据进行交换;
            }
        }
    }
}

//测试对一组整型数据进行排序;
void test1()
{
    int arr[] = {1,3,5,7,9,2,4,6,8,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    com(arr,sz,sizeof(arr[0]),com_int);
    int i = 0;
    for(i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
}

//测试对一组浮点型数据进行排序;
void test2()
{
    float a[] = {1.2,2.2,3.4,5.6,1.2,4.5,8.5,9.1};
    int sz = sizeof(a)/sizeof(a[0]);
    com(a,sz,sizeof(a[0]),com_float);
    int i = 0;
    for(i=0;i<sz;i++)
    {
        printf("%lf ",a[i]);
    }
}

//测试对一组结构体数据进行排序;
void test3()
{
    struct stu s1[3] = {{"zhangsan",20},{"lisi",64},{"wangwu",43}};
    int sz = sizeof(s1)/sizeof(s1[0]);
    com(s1,sz,sizeof(s1[0]),com_struct_name);
    int i = 0;
    for(i=0;i<sz;i++)
    {
        printf("%s ",(s1+i)->name);
        printf("%d\n",(s1+i)->age);
    }
}

void test4()
{
    struct stu s1[3] = {{"zhangsan",20},{"lisi",64},{"wangwu",43}};
    int sz = sizeof(s1)/sizeof(s1[0]);
    com(s1,sz,sizeof(s1[0]),com_struct_age);
    int i = 0;
    for(i=0;i<sz;i++)
    {
        printf("%s ",(s1+i)->name);
        printf("%d\n",(s1+i)->age);
    }
}

int main()
{
    test1();//给整型数据排序；
    printf("\n");
    test2();
    printf("\n");
    printf("\n");
    test3();
    printf("\n");
    test4();
    return 0;
}