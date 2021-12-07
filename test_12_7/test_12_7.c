#include <stdio.h>

//结构体内存对齐
//练习1
/*struct S1
{
    char c1;
    int i;
    char c2;
};
    
//练习2
struct S2
{
    char c1;
    char c2;
    int i;
};
    
//练习3
struct S3
{
    double d;
    char c;
    int i;
};

//练习4-结构体嵌套问题
struct S4
{
    char c1;
    struct S3 s3;
    double d;
};
    
int main()
    {
        printf("%d\n",sizeof(struct S1));
        printf("%d\n",sizeof(struct S2));
        printf("%d\n",sizeof(struct S3));
        printf("%d\n",sizeof(struct S4));
        return 0;
    }*/

//例如：
/*struct S1
{
    char c1;
    int i;
    char c2;
};
struct S2
{
    char c1;
    char c2;
    int i;
};

int main()
{
    printf("%d\n",sizeof(struct S1));
    printf("%d\n",sizeof(struct S2));
    return 0;
}*/

/*
//修改默认对齐数
#pragma pack(8)//设置默认对齐数为8
struct S1
{
    char c1;
    int i;
    char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
#pragma pack(1)//设置默认对齐数为1
struct S2
{
    char c1;
    int i;
    char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
int main()
{
    //输出的结果是什么？
    printf("%d\n", sizeof(struct S1));
    printf("%d\n", sizeof(struct S2));
    return 0;
}*/


//结构体传参
struct S 
{
    int data[1000];
    int num;
};
struct S s = {{1,2,3,4}, 1000};
//结构体传参
void print1(struct S s) 
{
    printf("%d\n", s.num);
}
//结构体地址传参
void print2(struct S* ps) 
{
    printf("%d\n", ps->num);
}
int main()
{
    print1(s);//传结构体
    print2(&s); //传地址
    return 0; 
}

