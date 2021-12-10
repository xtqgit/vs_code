#include <contact.h>

//初始化通讯录
void InitContact(struct contact* p)
{
    p->data = (struct PeoInfo*)malloc(CAPACITY * sizeof(struct PeoInfo));
    if(p->data == NULL)
    {
        return;
    }
    p->size = 0;
    p->capacity = CAPACITY;
    //将文件中的数据加载到内存中;
    LoadContact(p);
}

//检查空间是否会超出容量，如果超出容量则应增加内存容量;
void addcapacity(struct contact* p)
{
    if(p->size == p->capacity)
    {
        struct PeoInfo* ptr = realloc (p->data,(p->capacity+2)*sizeof(struct PeoInfo));
        if(ptr != NULL)
            p->data = ptr;
            p->capacity += 2;
    }
}

//添加
void Addcontact(struct contact* p)
{
    //检查空间是否会超出容量，如果超出容量则应增加内存容量;
    addcapacity(p);
    printf("请输入要添加的姓名:\n");
    scanf("%s",p->data[p->size].name);
    printf("请输入要添加的年龄:\n");
    scanf("%d",&(p->data[p->size].age));
    printf("请输入要添加的性别:\n");
    scanf("%s",p->data[p->size].sex);
    printf("请输入要添加的电话:\n");
    scanf("%s",p->data[p->size].tele);
    printf("请输入要添加的地址:\n");
    scanf("%s",p->data[p->size].addr);

    p->size++;
    printf("添加成功\n");
}

//打印通讯录;
void Printcontact(const struct contact* p)
{
    if (p->size == 0)
	{
		printf("通讯录为空，无需打印\n");
		return;
	}
    int i = 0;
    //打印标题;
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
    //打印信息;
    for(i=0;i<p->size;i++)
    {
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",p->data[i].name,
                                                   p->data[i].age,
                                                   p->data[i].sex,
                                                   p->data[i].tele,
                                                   p->data[i].addr);
    }
}

//查找函数
//找到时返回姓名对应的结构体相对位移;
//未找到时返回-1;
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

	return -1;//找不到
}

//删除通讯录
void Delcontact(struct contact* p)
{
    char name[MAX_NAME] = {0};
    if (p->size == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
    printf("请输入需要删除的姓名:>");
    scanf("%s",name);
    //查找通讯录中有无对应的姓名;
    int ret = FindByName(p,name);

    if(ret == -1)
    {
        printf("通讯录中不存在对应人的信息\n");
        //return;
    }
    else
    {
        for(ret;ret<p->size-1;ret++)
        {
            p->data[ret] = p->data[ret+1];
        }
        p->size--;
        printf("删除成功\n");
    }
}

//搜索姓名
void Searchcontact(const struct contact* p)
{
    char name[MAX_NAME] = {0};
    printf("请输入需要查找的姓名:>");
    scanf("%s",name);
    //查找;
    int ret = FindByName(p,name);

    if(ret == -1)
    {
        printf("通讯录中不存在要查找的人\n");
        return;
    }
    else//打印;
    {
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
    //打印信息;
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n",p->data[ret].name,
                                                   p->data[ret].age,
                                                   p->data[ret].sex,
                                                   p->data[ret].tele,
                                                   p->data[ret].addr);
    }
}

//修改信息;
void Modifycontact(struct contact* p)
{
    char name[MAX_NAME] = {0};
    printf("请输入需要修改的姓名:>");
    scanf("%s",name);
    //查找;
    int ret = FindByName(p,name);

    if(ret == -1)
    {
        printf("通讯录中不存在输入姓名相同的信息\n");
    }
    else
    {
        strcpy(p->data[ret].name,name);
        printf("请输入要修改的年龄:\n");
        scanf("%d",&(p->data[ret].age));
        printf("请输入要修改的性别:\n");
        scanf("%s",p->data[ret].sex);
        printf("请输入要修改的电话:\n");
        scanf("%s",p->data[ret].tele);
        printf("请输入要修改的地址:\n");
        scanf("%s",p->data[ret].addr);
        printf("修改信息成功\n");
    }
}

void exitcontact(struct contact* p)
{
    free(p->data);
    p->data = NULL;
}

void Savecontact(const struct contact* p)
{
    //以二进制只写方式打开Contacts.bit文件;
    FILE* fpwrt = fopen("Contacts.bit","wb");
    if(fpwrt == NULL)
    {
        //打开文件失败
        printf("%s\n",strerror(errno));
        return;
    }
    int i = 0;
    for(i=0;i<p->size;i++)
    {
        fwrite(&(p->data[i]),sizeof(struct PeoInfo),1,fpwrt);
    }
    fclose(fpwrt);
    fpwrt = NULL;
}

void LoadContact(struct contact* p)
{
    struct PeoInfo temp; 
    FILE* fpread = fopen("Contacts.bit","rb");
    if(fpread == NULL)
    {
        printf("读取文件时打开失败：%s\n",strerror(errno));
        return;
    }

    while(fread(&temp,sizeof(struct PeoInfo),1,fpread))
    {
        //检查空间是否会超出容量，如果超出容量则应增加内存容量;
        addcapacity(p);
        p->data[p->size] = temp;
        p->size++;
    }

    fclose(fpread);
    fpread = NULL;
}