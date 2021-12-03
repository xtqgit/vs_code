#include <stdio.h>

//冒泡排序
void maopao(int* arr,int sz)
{
    int i = 0;
    for(i=0;i<sz-1;i++)
    {
        int j = 0;
        int flag = 1;
        int temp = 0;
        for(j=0;j<sz-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 0;
            }
        }
        if(flag==1)
        {
            break;
        }
    }
}

int main()
{
    int i = 0;
    int arr[] = {9,8,6,7,5,4,3,2,1,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    maopao(arr,sz);
    for(i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}