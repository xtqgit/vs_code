#include <stdio.h>
#include <string.h>

#define MAX 1000    //ͨѶ¼��С
#define MAX_NAME 20 //����
#define MAX_SEX 5//�Ա�
#define MAX_TELE 12 //�绰
#define MAX_ADDR 10 //��ַ

struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

struct contact
{
    struct PeoInfo data[MAX];//�����ӽ������˵���Ϣ
    int size;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
};

void InitContact(struct contact* p);//��ʼ��ͨѶ¼;
void Addcontact(struct contact* p);//���;
void Delcontact(struct contact* p);//ɾ��ͨѶ¼;
void Searchcontact(const struct contact* p);//����;
void Modifycontact(struct contact* p);//�޸�;
//void Sortcontact(const struct contact* p);//����;
void Printcontact(const struct contact* p);//��ӡ;