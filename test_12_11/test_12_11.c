#include <stdio.h>

/*
int g_val = 2016;
void print(const char *str)
{
    printf("%s\n", str);
}
*/

/*
#include <stdio.h>
int main()
{
    extern void print(char *str);
    extern int g_val;
    printf("%d\n", g_val);
    print("hello bit.\n");
    return 0;
}
 */

/*
#include <stdio.h>
int main()
{
    int i = 0;
    for(i=0; i<10; i++)
    {
        printf("%d ", i);
    }
    return 0;
}
 */

/*
#define MAX 1000
#define reg register ? ? ? ? ?//Ϊ register����ؼ��֣�����һ����̵�����
#define do_forever for(;;) ? ? //�ø�����ķ������滻һ��ʵ��
#define CASE break;case ? ? ? ?//��дcase����ʱ���Զ��� breakд�ϡ�
// �������� stuff���������Էֳɼ���д���������һ���⣬ÿ�еĺ��涼��һ����б��(���з�)��
#define DEBUG_PRINT printf("file:%s\tline:%d\t \
 ? ? ? ? ? ? ? ? ? ? ? ? ?date:%s\ttime:%s\n" ,\
 ? ? ? ? ? ? ? ? ? ? ? ? ?__FILE__,__LINE__ , ? ? ? \
 ? ? ? ? ? ? ? ? ? ? ? ? ?__DATE__,__TIME__ )
 */

/*
if(condition)
    max = MAX;
else
    max = 0;
 */

/*
int main()
{
    char* p = "hello ""bit\n";
    printf("hello"" bit\n");
    printf("%s", p);
    return 0;
}
*/

/*
#define PRINT(FORMAT, VALUE)\
    printf("the value of " #VALUE "is "FORMAT "\n", VALUE);

int main()
{
    int i = 10;
    PRINT("%d", i+3);//������ʲôЧ����
    return 0;
}
*/

/*
#define ADD_TO_SUM(num, value) \
    sum##num += value;
int main()
{
    int sum5 = 0;
    ADD_TO_SUM(5, 10);//�����ǣ���sum5����10.
    printf("%d\n",sum5);
    return 0;
}
*/


#define MAX(a, b) ( (a) > (b) ? (a) : (b) )
int main()
{
    int x = 5;
    int y = 8;
    int z = MAX(x++, y++);
    printf("x=%d y=%d z=%d\n", x, y, z);//����Ľ����ʲô��
    return 0;
}


/*
#define MALLOC(num, type)\
    (type *)malloc(num * sizeof(type))

int main()
{
    //ʹ��
    MALLOC(10, int);//������Ϊ����
    //Ԥ�������滻֮��
    (int *)malloc(10 * sizeof(int));
    return 0;
}
*/

/*
#include <stdio.h>
int main()
{
    int array [ARRAY_SIZE];
    int i = 0;
    for(i = 0; i< ARRAY_SIZE; i ++)
    {
        array[i] = i;
    }
    for(i = 0; i< ARRAY_SIZE; i ++)
    {
        printf("%d " ,array[i]);
    }
    printf("\n" );
    return 0;
}
*/

/*
#include <stdio.h>
#define __DEBUG__

int main()
{
    int i = 0;
    int arr[10] = {0};
    for(i=0; i<10; i++)
    {
        arr[i] = i;
        #ifdef __DEBUG__
        printf("%d\n", arr[i]);//Ϊ�˹۲������Ƿ�ֵ�ɹ��� 
        #endif //__DEBUG__
    }
    return 0;
}
*/
/*
#if defined(OS_UNIX)
    #ifdef OPTION1
        unix_version_option1();
    #endif
    #ifdef OPTION2
        unix_version_option2();
    #endif
#elif defined(OS_MSDOS)
    #ifdef OPTION2
        msdos_version_option2();
    #endif
#endif
*/















