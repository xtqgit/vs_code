#include <stdio.h>
#include <string.h>

//��׼�ⷨ
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

//�����ⷨ;
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
    len_move(arr,arr+k-1);//�����Ƶ��ֽڷ�ת
    len_move(arr+k,arr+len-1);//��ʣ����ֽڷ�ת
    len_move(arr,arr+len-1);//�������ֽڽ��з�ת
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

//��len���ȵ��ַ�����s1��չ��Ϊ����Ϊ2*len���ȵ��ַ���,��strncat������ͬ;
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

//�Ƚ��ַ���s1��s2��ͬ����len�ַ����ݣ���ͬ�򷵻�1�����򷵻�0,��strstr������ͬ;
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

//�ж�s2�ǲ���s1��������������ҷ�ת�õ�;
int left_move(char* s1,char* s2)
{
    int i = 0;
    int len = strlen(s1);
    int len1 = strlen(s2);
    if(len != len1)//���Ȳ���ȿ϶�����ͨ����ת�õ���ֱ�ӷ���0;
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
    //strstr(s1,s2)������Ѱ��s2�Ƿ���s1���ִ�������Ƿ����ִ���s1�е���ʵ��ַ�����򷵻ؿ�ָ��;
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
        printf("�ҵ���\n");
    else
        printf("û�ҵ�\n");
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
        printf("�ҵ���\n");
        printf("x = %d,y = %d\n",x,y);
    }
    else
        printf("û�ҵ�\n");
}