#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    //����1
    int num = 0;
    scanf("%d", &num);
    int arr[num] = {0};
    //����2
    int* ptr = NULL;
    ptr = (int*)malloc(num*sizeof(int));
    if(NULL != ptr)//�ж�ptrָ���Ƿ�Ϊ��
    {
        int i = 0;
        for(i=0; i<num; i++)
        {
            *(ptr+i) = 0;
        }
    }
    free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
    ptr = NULL;//�Ƿ��б�Ҫ��
    return 0;
}*/

/*
int main()
{
    int *p = (int*)calloc(10, sizeof(int));
    if(NULL != p)
    {
    //ʹ�ÿռ�
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
        //ҵ����
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    //��չ����
    //����1
    ptr = (int*)realloc(ptr, INT_MAX);//����������(�������ʧ�ܻ���Σ�)
 
     //����2
    int*p = NULL;
    p = realloc(ptr, 1000);
    if(p != NULL)
    {
        ptr = p;
    }
    //ҵ����
    free(ptr);
    return 0;
}
*/

//3.1 ��NULLָ��Ľ����ò���
/*void test()
{
    int *p = (int *)malloc(INT_MAX/4);
    *p = 20;//���p��ֵ��NULL���ͻ�������
    free(p);
}
*/

//3.2 �Զ�̬���ٿռ��Խ�����
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
       *(p+i) = i;//��i��10��ʱ��Խ�����
    }
    free(p);
}
*/

//3.3 �ԷǶ�̬�����ڴ�ʹ��free�ͷ�
/*
void test()
{
    int a = 10;
    int *p = &a;
    free(p);//ok?
}
*/

//3.4 ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
/*
void test()
{
    int *p = (int *)malloc(100);
    p++;
    free(p);//p����ָ��̬�ڴ����ʼλ��
}
*/

//3.5 ��ͬһ�鶯̬�ڴ����ͷ�
/*
void test()
{
    int *p = (int *)malloc(100);
    free(p);
    free(p);//�ظ��ͷ�
}
*/

//3.6 ��̬�����ڴ������ͷţ��ڴ�й©��
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
//��������
typedef struct st_type
{
    int i;
    int a[0];//���������Ա
}type_a;
*/

/*
typedef struct st_type
{
    int i;
    int a[];//���������Ա
}type_a;

int main()
{
    return 0;
}
*/

/*
//�������鿪�ٿռ�
//code1
typedef struct st_type
{
 int i;
 int a[0];//���������Ա
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

//�������������
//����2
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
    //ҵ����
    int i = 0;
    for(i=0; i<100; i++)
    {
        p->p_a[i] = i;
    }
    //�ͷſռ�
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
