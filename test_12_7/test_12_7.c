#include <stdio.h>

//�ṹ���ڴ����
//��ϰ1
/*struct S1
{
    char c1;
    int i;
    char c2;
};
    
//��ϰ2
struct S2
{
    char c1;
    char c2;
    int i;
};
    
//��ϰ3
struct S3
{
    double d;
    char c;
    int i;
};

//��ϰ4-�ṹ��Ƕ������
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

//���磺
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
//�޸�Ĭ�϶�����
#pragma pack(8)//����Ĭ�϶�����Ϊ8
struct S1
{
    char c1;
    int i;
    char c2;
};
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
#pragma pack(1)//����Ĭ�϶�����Ϊ1
struct S2
{
    char c1;
    int i;
    char c2;
};
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
int main()
{
    //����Ľ����ʲô��
    printf("%d\n", sizeof(struct S1));
    printf("%d\n", sizeof(struct S2));
    return 0;
}*/


//�ṹ�崫��
struct S 
{
    int data[1000];
    int num;
};
struct S s = {{1,2,3,4}, 1000};
//�ṹ�崫��
void print1(struct S s) 
{
    printf("%d\n", s.num);
}
//�ṹ���ַ����
void print2(struct S* ps) 
{
    printf("%d\n", ps->num);
}
int main()
{
    print1(s);//���ṹ��
    print2(&s); //����ַ
    return 0; 
}

