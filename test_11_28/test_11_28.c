//#include <stdio.h>

//ָ������;
/*int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int* arr[3] = {&a,&b,&c};

    int i = 0;
    for(i=0;i<3;i++)
    {
        printf("%d ",*arr[i]);
    }
    return 0;
}
#include <stdio.h>
int i ;

int main()

{
    i--;
    if(i>sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}*/

/*#include <stdio.h>

int count_bit_one(int a)
{
    int i = 0;
    int count = 0;
    for(i=0;i<32;i++)
    {
        if(a & 1)
        {
            count++;
        }
        a >>= 1;
    }
    return count;
}

int main()
{
    int a;
    scanf("%d",&a);
    int count = count_bit_one(a);
    printf("%d\n",count);
}*/

/*#include <stdio.h>

int count_bit_one(int a)
{
    int count = 0;
    while(a)
    {
        a = a & (a-1);
        count++;
    }
    return count;
}

int main()
{
    int a;
    scanf("%d",&a);
    int count = count_bit_one(a);
    printf("%d\n",count);
}*/

/*#include <stdio.h>

int get_diff_bit(int a,int b)
{
    int m = a ^ b;
    int count = 0;
    while(m)
    {
        m = m & (m-1);
        count++;
    }
    return count;
}

int main()
{
    int a=0,b=0;
    scanf("%d%d",&a,&b);
    int count = get_diff_bit(a,b);
    printf("%d\n",count);
    return 0;
}*/

/*#include <stdio.h>

void print(int m)
{
    int i = 0;
    printf("��ӡ����λ��");
    for(i=30;i>=0;i -= 2)
    {
        printf("%d ",((m >> i) & 1));
    }
    printf("\n");
    printf("��ӡż��λ��");
    for(i=31;i>=1;i -= 2)
    {
        printf("%d ",((m >> i) & 1));
    }
    printf("\n");
}
int main()
{
    int m;
    scanf("%d",&m);
    print(m);
    return 0;
}*/

/*#include <stdio.h>

int main()
{
    int m = 0;
    int n = 0;
    scanf("%d%d",&m,&n);
    printf("m = %d\n",m);
    printf("n = %d\n",n);
    m = m ^ n;
    n = m ^ n;
    m = m ^ n;
    printf("����֮��\n");
    printf("m = %d\n",m);
    printf("n = %d\n",n);
    return 0;
}*/

/*#include <stdio.h>

void print(int* m,int n)
{
    int i = 0;
    for(i=0;i<n;i++)
    {
        printf("%d ",*(m+i));
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr,sz);
    return 0;
}*/

/*#include <stdio.h>

int main()
{
    int i = 0;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    for(i=0;i<12;i++)
    {
        printf("hehe\n");
        arr[i] = 0;
    }
}*/

/*#include <stdio.h>

void my_strcpy(char* arr1,char* arr2)
{
    while(*arr2!='\0')
    {
        *arr1 = *arr2;
        arr1++;
        arr2++;
    }
    *arr1 = *arr2;
}

int main()
{
    char arr1[] = "########################";
    char arr2[] = "bit";
    my_strcpy(arr1,arr2);
    printf("%s\n",arr1);
}*/

/*#include <stdio.h>

void my_strcpy(char* arr1,char* arr2)
{
    while(*arr1++ = *arr2++)
    {
        ;
    }
}

int main()
{
    char arr1[] = "########################";
    char arr2[] = "bit";
    my_strcpy(arr1,arr2);
    printf("%s\n",arr1);
}*/

/*#include <stdio.h>
#include <assert.h>

void my_strcpy(char* dest,char* scr)
{
    assert(dest != NULL);//����
    assert(scr != NULL);//����
    while(*dest++ = *scr++)
    {
        ;
    }        
}

int main()
{
    char arr1[] = "########################";
    char arr2[] = "bit";
    my_strcpy(arr1,arr2);
    printf("%s\n",arr1);
}*/

/*#include <stdio.h>

int main()
{
    int n = 100;
    const int num = 10;
    //const ����ָ�������*���ʱ�����ε���*p����ʱ����ͨ��p���ı�*p��ֵ��
    //const ����ָ�������*�ұ�ʱ�����ε���ָ�����p����p���ܱ��ı䣻
    const int* p = &num;
    int *const m = &num;

    p = &n;
    *m = 30;

    *p = 20;//����;
    m = &n; //����;
    printf("%d\n",num);
    return 0;
}*/

#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest,const char* scr)
{
    char* ret = dest;
    assert(dest != NULL);//���ԣ�����������ʱ����ʱ������������ʱ������û��Ӱ�죻
    assert(scr != NULL);//����
    while(*dest++ = *scr++)
    {
        ;
    }
    return ret;  
}

int main()
{
    char arr1[] = "########################";
    char arr2[] = "bit";
    
    printf("%s\n",my_strcpy(arr1,arr2));
}