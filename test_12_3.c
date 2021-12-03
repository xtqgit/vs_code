#include <stdio.h>
#include <string.h>

struct stu{
    char name[20];
    int age;
};

//�������ͱ����Ƚϴ�С������ֵΪx-y;
int com_int(void* x,void* y)
{
    return *(int*)x - *(int*)y;
}

//���������ͱ����Ƚϴ�С������ֵΪx-y;
int com_float(void* x,void* y)
{
    return (int)(*(float*)x - *(float*)y);
}

//�����ṹ������Ƚϴ�С������ֵΪx-y;
int com_struct_name(void* x,void* y)
{
    return strcmp(((struct stu*)x)->name,((struct stu*)y)->name);
}

int com_struct_age(void* x,void* y)
{
    return (int)(((struct stu*)x)->age - ((struct stu*)y)->age);
}

//���������ݽ��н���;
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

//ð�������㷨����ʵ�֣�
void com(void* arr,int sz,int with,int (*comper)(void* e1,void* e2))
{
    int i = 0;
    for(i=0;i<sz-1;i++)
    {
        int j = 0;
        for(j=0;j<sz-1-i;j++)
        {
            if((*comper)(((char*)arr) + j*with ,((char*)arr) + (j+1)*with) > 0)//�Ƚ�arr[j]��arr[j+1]�Ĵ�С;
            {
                swp(((char*)arr) + j*with,((char*)arr) + (j+1)*with,with);//���arr[j]����arr[j+1]����arr[j]��arr[j+1]�����ݽ��н���;
            }
        }
    }
}

//���Զ�һ���������ݽ�������;
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

//���Զ�һ�鸡�������ݽ�������;
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

//���Զ�һ��ṹ�����ݽ�������;
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
    test1();//��������������
    printf("\n");
    test2();
    printf("\n");
    printf("\n");
    test3();
    printf("\n");
    test4();
    return 0;
}