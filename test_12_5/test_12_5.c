#include <stdio.h>
#include <string.h>

//标准解法
/*void move(char* arr,int k)
{
    //asser(arr);
    int len = strlen(arr);
    int i = 0;
    for(i=0;i<k;i++)
    {
        char temp = *arr;
        int j = 0;
        for(j=0;j<len-1;j++)
        {
            *(arr + j) = *(arr + j + 1);
        }
        *(arr + len - 1) = temp;
    }
}*/

//三步解法;
/*void len_move(char* left,char* right)
{
    char temp;
    while(left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

void move(char* arr,int k)
{
    int len = strlen(arr);
    len_move(arr,arr+k-1);//将左移的字节翻转
    len_move(arr+k,arr+len-1);//将剩余的字节翻转
    len_move(arr,arr+len-1);//将所有字节进行翻转
}

int left_move(char* arr1,char* arr2)
{
    int i =0;
    int len = strlen(arr1);
    for(i=0;i<len;i++)
    {
        move(arr1,1);
        if(strcmp(arr1,arr2)==0)
            return 1;
    }
    return 0;
}*/

//将len长度的字符串是s1扩展成为长度为2*len长度的字符串,与strncat函数相同;
/*void my_strcpy(char* s1,int len)
{
    int i = 0;
    for(i=0;i<len;i++)
    {
        *(s1 + len + i) = *(s1 + i);
    }
    *(s1 + 2*len) = '\0';
    printf("%s\n",s1);
}

//比较字符串s1与s2相同长度len字符内容，相同则返回1，否则返回0,与strstr函数相同;
int my_strcmp(char* s1,char* s2,int len)
{
    int i = 0;
    for(i=0;i<len;i++)
    {
       if(*(s1+i) != *(s2+i))
            return 0;
    }
    return 1;
}

//判断s2是不是s1经过向左或者向右翻转得到;
int left_move(char* s1,char* s2)
{
    int i = 0;
    int len = strlen(s1);
    int len1 = strlen(s2);
    if(len != len1)//长度不相等肯定不能通过翻转得到，直接返回0;
        return 0;
    my_strcpy(s1,len);
    for(i=0;i<len;i++)
    {
        if(my_strcmp(s1+i,s2,len))
            return 1;
    }
    return 0;
}

int main()
{
    char arr1[30] = "abcdef";
    char arr2[] = "cdefab";
    if(left_move(arr1,arr2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}*/

/*int left_move(char* s1,char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2)
        return 0;
    strncat(s1,s1,len1);
    //strstr(s1,s2)函数，寻找s2是否是s1的字串，如果是返回字串在s1中的其实地址，否则返回空指针;
    if(strstr(s1,s2)==NULL)
        return 0;
    else
        return 1;
}

int main()
{
    char arr1[30] = "abcdef";
    char arr2[] = "cdefab";
    if(left_move(arr1,arr2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}*/

/*int findnum(int arr[3][3],int k,int row,int col)
{
    int x = 0;
    int y = col - 1;
    while(x<=row-1 && y>=0)
    {
        if(arr[x][y]>k)
        {
            y--;
        }
        else if(arr[x][y]<k)
        {
            x++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int x = 3;
    int y = 3;
    int k = 7;

    int flag = findnum(arr,k,x,y);
    if(flag == 1)
        printf("找到了\n");
    else
        printf("没找到\n");
}*/

int findnum(int arr[3][3],int k,int* row,int* col)
{
    int x = 0;
    int y = *col - 1;
    while(x<=*row-1 && y>=0)
    {
        if(arr[x][y]>k)
        {
            y--;
        }
        else if(arr[x][y]<k)
        {
            x++;
        }
        else
        {
            *row = x;
            *col = y;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int x = 3;
    int y = 3;
    int k = 7;

    int flag = findnum(arr,k,&x,&y);
    if(flag == 1)
    {
        printf("找到了\n");
        printf("x = %d,y = %d\n",x,y);
    }
    else
        printf("没找到\n");
}