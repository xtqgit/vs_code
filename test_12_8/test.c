#include <stdio.h>
#include <string.h>

#define MAX 1000    //ͨѶ¼��С
#define MAX_NAME 20 //����
#define MAX_SEX 5//�Ա�
#define MAX_TELE 12 //�绰
#define MAX_ADDR 10 //��ַ

enum Option
{
	EXIT = 0,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

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

void interface();//��ӡ��ʼҳ��;
void InitContact(struct contact* p);//��ʼ��ͨѶ¼;
void Addcontact(struct contact* p);//���;
void Delcontact(struct contact* p);//ɾ��ͨѶ¼;
void Searchcontact(const struct contact* p);//����;
void Modifycontact(struct contact* p);//�޸�;
//void Sortcontact(const struct contact* p);//����;
void Printcontact(const struct contact* p);//��ӡ;

int main()
{
    int input;
    struct contact con;
    //��ӡ��ʼ����;
    interface();
    //��ʼ��ͨѶ¼;
    InitContact(&con);
    do
    {
        printf("������:>");
        scanf("%d",&input);
        switch (input)
        {
        case EXIT:
            printf("�˳��ɹ�\n");
            break;
        case ADD:
            Addcontact(&con);//���ͨѶ¼
            break;
        case DEL:
            Delcontact(&con);//ɾ��ͨѶ¼
            break;
        case SEARCH:
            Searchcontact(&con);//����;
            break;
        case MODIFY:
            Modifycontact(&con);//�޸�;
            break;
        case SORT:
            //Sortcontact(&con);//����;
            break;
        case PRINT:
            Printcontact(&con);//��ӡ;
            break;
        
        default:
            printf("�����������������:>\n");
            break;
        }
    } while (input);
    

    return 0;
}

//��ӡ��ʼҳ��;
void interface()
{
    printf("*****************************************\n");
    printf("********0->exit        1->add************\n");
    printf("********2->del         3->search*********\n");
    printf("********4->modify      5->sort***********\n");
    printf("********6->print              ***********\n");
    printf("*****************************************\n");
}

//��ʼ��ͨѶ¼
void InitContact(struct contact* p)
{
    p->size = 0;
    memset(p->data, 0, sizeof(p->data));
}

//���
void Addcontact(struct contact* p)
{
    if(p->size == MAX)
    {
        printf("ͨѶ¼���������ʧ��\n");
        return;
    }
    else
    {
        printf("������Ҫ��ӵ�����:\n");
        scanf("%s",p->data[p->size].name);
        printf("������Ҫ��ӵ�����:\n");
        scanf("%d",&(p->data[p->size].age));
        printf("������Ҫ��ӵ��Ա�:\n");
        scanf("%s",p->data[p->size].sex);
        printf("������Ҫ��ӵĵ绰:\n");
        scanf("%s",p->data[p->size].tele);
        printf("������Ҫ��ӵĵ�ַ:\n");
        scanf("%s",p->data[p->size].addr);

        p->size++;
        printf("��ӳɹ�\n");
    }
}

//��ӡͨѶ¼;
void Printcontact(const struct contact* p)
{
    if (p->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ������ӡ\n");
		return;
	}
    int i = 0;
    //��ӡ����;
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
    //��ӡ��Ϣ;
    for(i=0;i<p->size;i++)
    {
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",p->data[i].name,
                                                   p->data[i].age,
                                                   p->data[i].sex,
                                                   p->data[i].tele,
                                                   p->data[i].addr);
    }
}

//���Һ���
//�ҵ�ʱ����������Ӧ�Ľṹ�����λ��;
//δ�ҵ�ʱ����-1;
static int FindByName(const struct contact* p, char name[])
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
		{
			return i;
		}
	}

	return -1;//�Ҳ���
}

//ɾ��ͨѶ¼
void Delcontact(struct contact* p)
{
    char name[MAX_NAME] = {0};
    if (p->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
    printf("��������Ҫɾ��������:>");
    scanf("%s",name);
    //����ͨѶ¼�����޶�Ӧ������;
    int ret = FindByName(p,name);

    if(ret == -1)
    {
        printf("ͨѶ¼�в����ڶ�Ӧ�˵���Ϣ\n");
        //return;
    }
    else
    {
        for(ret;ret<p->size-1;ret++)
        {
            p->data[ret] = p->data[ret+1];
        }
        p->size--;
        printf("ɾ���ɹ�\n");
    }
}

//��������
void Searchcontact(const struct contact* p)
{
    char name[MAX_NAME] = {0};
    printf("��������Ҫ���ҵ�����:>");
    scanf("%s",name);
    //����;
    int ret = FindByName(p,name);

    if(ret == -1)
    {
        printf("ͨѶ¼�в�����Ҫ���ҵ���\n");
        return;
    }
    else//��ӡ;
    {
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
    //��ӡ��Ϣ;
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",p->data[ret].name,
                                                   p->data[ret].age,
                                                   p->data[ret].sex,
                                                   p->data[ret].tele,
                                                   p->data[ret].addr);
    }
}

//�޸���Ϣ;
void Modifycontact(struct contact* p)
{
    char name[MAX_NAME] = {0};
    printf("��������Ҫ�޸ĵ�����:>");
    scanf("%s",name);
    //����;
    int ret = FindByName(p,name);

    if(ret == -1)
    {
        printf("ͨѶ¼�в���������������ͬ����Ϣ\n");
    }
    else
    {
        strcpy(p->data[ret].name,name);
        printf("������Ҫ�޸ĵ�����:\n");
        scanf("%d",&(p->data[ret].age));
        printf("������Ҫ�޸ĵ��Ա�:\n");
        scanf("%s",p->data[ret].sex);
        printf("������Ҫ�޸ĵĵ绰:\n");
        scanf("%s",p->data[ret].tele);
        printf("������Ҫ�޸ĵĵ�ַ:\n");
        scanf("%s",p->data[ret].addr);
        printf("�޸���Ϣ�ɹ�\n");
    }
}