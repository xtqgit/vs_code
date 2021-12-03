#include <stdio.h>

//判断一个数是否为素数
/*int is_prime(int n)
{
    int i = 0;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;    
}

int main()
{
    int i = 0;
    for(i=100;i<=200;i++)
    {
        if(is_prime(i)==1)
        printf("%d\n",i);
    }
    return 0;
}*/

//判断一年是否为闰年
/*int is_leap_year(int i)
{
    if((i%4==0 && i%100!=0) || (i%400==0))
        return 1;
    else
        return 0;
}

int main()
{
    int year=1000;
    for(year==1000;year<=2000;year++)
    {
        if(is_leap_year(year))
        {
            printf("%d年是闰年\n",year);
        }
    }
    return 0;
}*/

//二分法查找一个数；
/*int binary_search(int arr[],int k,int sz)
{
    int left = 0;
    int right = sz - 1;
    while(left <= right)
    {
        sz = (left+right)/2;
        if(arr[sz]<k)
        {
            left = sz + 1;
        }
        else if(arr[sz]>k)
        {   
            right = sz - 1;
        }
        else
        {
            return sz;
        }
    }
    return -1;
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int k = 7;
    int b = sizeof(arr)/sizeof(arr[0]);
    int a = 0;
    a = binary_search(arr,k,b);
    if(a==-1)
    {
        printf("没有这个数\n");
    }
    else
    {
        printf("%d\n",a);
    }
}*/

//链式调用
int main()
{
    printf("%d",printf("%d",printf("%d",43)));//输出4321,printf函数返回值为打印字符的个数；
    return 0;
}