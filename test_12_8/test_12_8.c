#include <stdio.h>
/*
struct A {
    int _a:2;
    int _b:5;
    int _c:10;
    int _d:30;
};

int main()
{
    printf("%d\n", sizeof(struct A));
    return 0;
}*/

//һ������
/*struct S {
    char a:3;
    char b:4;
    char c:5;
    char d:4;
};
int main()
{
    struct S s = {0};
    s.a = 10;
    s.b = 12;
    s.c = 3;
    s.d = 4;
    return 0;
}*/

//ö�ٵĶ���
/*
enum Day//����
{
    Mon,
    Tues,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};
enum Sex//�Ա�
{
    MALE,
    FEMALE,
    SECRET
};

enum Color//��ɫ
{
    RED,
    GREEN,
    BLUE
};
*/

//ö�����͸���ֵ
/*enum Color//��ɫ
{
    RED=1,
    GREEN=2,
    BLUE=4
};*/

//ö�ٵ�ʹ��

/*
enum Color//��ɫ
{
    RED=1,
    GREEN=2,
    BLUE=4
};
int main()
{
    enum Color clr = GREEN;//ֻ����ö�ٳ�����ö�ٱ�����ֵ���Ų���������͵Ĳ��졣
    clr = 5;               //ok??
    return 0;
}*/

//�������͵�����
/*union Un
{
    char c;
    int i;
};

int main()
{
    //���ϱ����Ķ���
    union Un un;
    //�������������Ĵ�С
    printf("%d\n", sizeof(un));
    return 0;
}*/

/*
union Un
{
 int i;
 char c;
};

int main()
{
    union Un un;
    // ��������Ľ����һ������
    printf("%d\n", &(un.i));
    printf("%d\n", &(un.c));
    //��������Ľ����ʲô��
    un.i = 0x11223344;
    un.c = 0x55;
    printf("%x\n", un.i);
    return 0;
}*/

//�ٶ�������

//����1
/*
int check_sys()
{
    union
    {
        int i;
        char c;
    }un;
    un.i = 1;
    return un.c; 
}
int main()
{
    int ret = check_sys();
    if(ret == 1)
    {
        printf("С��\n");
    }
    else
    {
        printf("���\n");
    }
    return 0; 
 }
*/

//������洢����
union Un1
{
    char c[5];
    int i;
};
union Un2
{
    short c[7];
    int i;
};
int main()
{
    //��������Ľ����ʲô��
    printf("%d\n", sizeof(union Un1));
    printf("%d\n", sizeof(union Un2));
    return 0;
}





