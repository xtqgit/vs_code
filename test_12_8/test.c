#include <stdio.h>
#include <string.h>

#define MAX 1000    //通讯录大小
#define MAX_NAME 20 //姓名
#define MAX_SEX 5//性别
#define MAX_TELE 12 //电话
#define MAX_ADDR 10 //地址

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
    struct PeoInfo data[MAX];//存放添加进来的人的信息
    int size;//记录的是当前通讯录中有效信息的个数
};

void interface();//打印初始页面;
void InitContact(struct contact* p);//初始化通讯录;
void Addcontact(struct contact* p);//添加;
void Delcontact(struct contact* p);//删除通讯录;
void Searchcontact(const struct contact* p);//搜索;
void Modifycontact(struct contact* p);//修改;
//void Sortcontact(const struct contact* p);//查找;
void Printcontact(const struct contact* p);//打印;

int main()
{
    int input;
    struct contact con;
    //打印初始界面;
    interface();
    //初始化通讯录;
    InitContact(&con);
    do
    {
        printf("请输入:>");
        scanf("%d",&input);
        switch (input)
        {
        case EXIT:
            printf("退出成功\n");
            break;
        case ADD:
            Addcontact(&con);//添加通讯录
            break;
        case DEL:
            Delcontact(&con);//删除通讯录
            break;
        case SEARCH:
            Searchcontact(&con);//搜索;
            break;
        case MODIFY:
            Modifycontact(&con);//修改;
            break;
        case SORT:
            //Sortcontact(&con);//查找;
            break;
        case PRINT:
            Printcontact(&con);//打印;
            break;
        
        default:
            printf("输入错误，请重新输入:>\n");
            break;
        }
    } while (input);
    

    return 0;
}

//打印初始页面;
void interface()
{
    printf("*****************************************\n");
    printf("********0->exit        1->add************\n");
    printf("********2->del         3->search*********\n");
    printf("********4->modify      5->sort***********\n");
    printf("********6->print              ***********\n");
    printf("*****************************************\n");
}

//初始化通讯录
void InitContact(struct contact* p)
{
    p->size = 0;
    memset(p->data, 0, sizeof(p->data));
}

//添加
void Addcontact(struct contact* p)
{
    if(p->size == MAX)
    {
        printf("通讯录已满，添加失败\n");
        return;
    }
    else
    {
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