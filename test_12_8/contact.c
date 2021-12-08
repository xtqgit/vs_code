#include <contact.h>

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