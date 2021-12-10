#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#define CAPACITY 3//��ʼ����
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
    struct PeoInfo* data;//�����ӽ������˵���Ϣ
    int size;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
    int capacity;
};

void InitContact(struct contact* p);//��ʼ��ͨѶ¼;
void Addcontact(struct contact* p);//���;
void Delcontact(struct contact* p);//ɾ��ͨѶ¼;
void Searchcontact(const struct contact* p);//����;
void Modifycontact(struct contact* p);//�޸�;
//void Sortcontact(const struct contact* p);//����;
void Printcontact(const struct contact* p);//��ӡ;
void Savecontact(const struct contact* p);//��������;
void exitcontact(struct contact* p);//�ͷŶ�̬�ڴ�;
void LoadContact(struct contact* p);//�����ļ����ڴ�