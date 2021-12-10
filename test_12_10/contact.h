#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#define CAPACITY 3//初始容量
#define MAX_NAME 20 //姓名
#define MAX_SEX 5//性别
#define MAX_TELE 12 //电话
#define MAX_ADDR 10 //地址

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
    struct PeoInfo* data;//存放添加进来的人的信息
    int size;//记录的是当前通讯录中有效信息的个数
    int capacity;
};

void InitContact(struct contact* p);//初始化通讯录;
void Addcontact(struct contact* p);//添加;
void Delcontact(struct contact* p);//删除通讯录;
void Searchcontact(const struct contact* p);//搜索;
void Modifycontact(struct contact* p);//修改;
//void Sortcontact(const struct contact* p);//查找;
void Printcontact(const struct contact* p);//打印;
void Savecontact(const struct contact* p);//保存数据;
void exitcontact(struct contact* p);//释放动态内存;
void LoadContact(struct contact* p);//加载文件到内存