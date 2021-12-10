#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    //代码1
    int num = 0;
    scanf("%d", &num);
    int arr[num] = {0};
    //代码2
    int* ptr = NULL;
    ptr = (int*)malloc(num*sizeof(int));
    if(NULL != ptr)//判断ptr指针是否为空
    {
        int i = 0;
        for(i=0; i<num; i++)
        {
            *(ptr+i) = 0;
        }
    }
    free(ptr);//释放ptr所指向的动态内存
    ptr = NULL;//是否有必要？
    return 0;
}*/

/*
int main()
{
    int *p = (int*)calloc(10, sizeof(int));
    if(NULL != p)
    {
    //使用空间
    }
    free(p);
    p = NULL;
    return 0;
}
*/

/*
int main()
{
    int *ptr = (int*)malloc(100);
    if(ptr != NULL)
    {
        //业务处理
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    //扩展容量
    //代码1
    ptr = (int*)realloc(ptr, INT_MAX);//这样可以吗？(如果申请失败会如何？)
 
     //代码2
    int*p = NULL;
    p = realloc(ptr, 1000);
    if(p != NULL)
    {
        ptr = p;
    }
    //业务处理
    free(ptr);
    return 0;
}
*/

//3.1 对NULL指针的解引用操作
/*void test()
{
    int *p = (int *)malloc(INT_MAX/4);
    *p = 20;//如果p的值是NULL，就会有问题
    free(p);
}
*/

//3.2 对动态开辟空间的越界访问
/*
void test()
{
    int i = 0;
    int *p = (int *)malloc(10*sizeof(int));
    if(NULL == p)
    {
        exit(EXIT_FAILURE);
    }
    for(i=0; i<=10; i++)
    {
       *(p+i) = i;//当i是10的时候越界访问
    }
    free(p);
}
*/

//3.3 对非动态开辟内存使用free释放
/*
void test()
{
    int a = 10;
    int *p = &a;
    free(p);//ok?
}
*/

//3.4 使用free释放一块动态开辟内存的一部分
/*
void test()
{
    int *p = (int *)malloc(100);
    p++;
    free(p);//p不再指向动态内存的起始位置
}
*/

//3.5 对同一块动态内存多次释放
/*
void test()
{
    int *p = (int *)malloc(100);
    free(p);
    free(p);//重复释放
}
*/

//3.6 动态开辟内存忘记释放（内存泄漏）
/*
void test()
{
    int *p = (int *)malloc(100);
    if(NULL != p)
    {
        *p = 20;
    }
}
int main()
{
    test();
    while(1);
}*/

/*
void GetMemory(char *p)
{
    p = (char *)malloc(100);
}
void Test(void)
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str, "hello world");
    printf(str);
}

int main()
{
    test();
    return 0;
}
*/

/*
char* GetMemory(void)
{
    char p[] = "hello world";
    return p;
}

void Test(void) 
{
    char *str = NULL;
    str = GetMemory();
    printf(str);
}

int main()
{
    Test();
    return 0;
}
*/

/*
void GetMemory(char **p, int num)
{
    *p = (char *)malloc(num);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello");
    printf(str);
}

int main()
{
    Test();
    return 0;
}
*/

/*
void Test(void)
{
    char *str = (char *) malloc(100);
    strcpy(str, "hello");
    free(str);
    if(str != NULL)
    {
        strcpy(str, "world");
        printf(str);
    }
}

int main()
{
    Test();
    return 0;
}
*/
/*
//柔性数组
typedef struct st_type
{
    int i;
    int a[0];//柔性数组成员
}type_a;
*/

/*
typedef struct st_type
{
    int i;
    int a[];//柔性数组成员
}type_a;

int main()
{
    return 0;
}
*/

/*
//柔性数组开辟空间
//code1
typedef struct st_type
{
 int i;
 int a[0];//柔性数组成员
}type_a;

int main()
{
    int i = 0;
    type_a *p = (type_a*)malloc(sizeof(type_a)+100*sizeof(int));
    p->i = 100;
    for(i=0; i<100; i++)
    {
        p->a[i] = i; 
    }

    for(i=0;i<100;i++)
    {
        printf("%d ",p->a[i]);
    }
    free(p);
    p = NULL;
    return 0;
}
*/

//柔性数组的优势
//代码2
/*
typedef struct st_type
{
    int i;
    int *p_a;
}type_a;

int main()
{
    type_a *p = (type_a *)malloc(sizeof(type_a));
    p->i = 100;
    p->p_a = (int *)malloc(p->i*sizeof(int));
    //业务处理
    int i = 0;
    for(i=0; i<100; i++)
    {
        p->p_a[i] = i;
    }
    //释放空间
    free(p->p_a);
    p->p_a = NULL;
    free(p);
    p = NULL;
    return 0;
}*/

  int test()
  {
        int x;
        return x == (1 && x);
  }

  int main()
  {
        int i = test();
        printf("%d\n",i);
        return 0;
  }
