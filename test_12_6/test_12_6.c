#include <stdio.h>
#include <string.h>

/*int my_strlen(const char* str)
{
    //assert(str);
    int i = 0;
    while(*str++)
    {
        i++;
    }
    return i;
}

int main()
{
 const char*str1 = "abcdef";
 int ret = my_strlen(str1);
 printf("str1长度为：%d\n",ret);
 return 0; 
 }*/

 /*char* my_strcpy(char* dest,const char* src)
 {
     asser(dest);
     asser(src);
     char* ret = dest;
     while(*dest++ = *src++)
     {
         ;
     }
     return ret;
 }

 int main()
 {
     char str1[] = "abcdef";
     char* str2 = "ghi";
     my_strcpy(str1,str2);
     printf("%s\n",str1);
 }*/

 /*char* my_strcat(char* dest,const char* src)
 {
     asser(dest);
     asser(src);
     char* ret = dest;
     while(*dest != '\0')
     {
         dest++;
     }

     while(*dest++ = *src++)
     {
         ;
     }
     return ret;
 }

 int main()
 {
     char str1[] = "abcdef";
     char* str2 = "ghi";
     my_strcat(str1,str2);
     printf("%s\n",str1);
 }*/

 /*int my_strcmp(const char* dest,const char* src)
 {
     asser(dest);
     asser(src);
     while(*dest || *src)
     {
         if((*dest != *src) || (!*dest) || (!*src))
         {
             return (int)(*dest - *src);
         }
         dest++;
         src++;
     }
     return 0;
 }

 int main()
 {
     char str1[] = "abcdef";
     char* str2 = "abcdefg";
     int ret = my_strcmp(str1,str2);
     printf("%d\n",ret);
 }*/


/*int my_strcmp(const char* dest,const char* src)
 {
     asser(dest && src);
     while(*dest == *src)
     {
         if(*dest=='\0')
         {
             return 0;
         }
         dest++;
         src++;
     }
     return *dest - *src;
 }

 int main()
 {
     char str1[] = "abcdef";
     char* str2 = "abcdefg";
     int ret = my_strcmp(str1,str2);
     printf("%d\n",ret);
 }*/

/*char* my_strncpy(char* dest,const char* src,size_t num)
 {
     //asser(dest && src);
     char* ret = dest;
     while(num--)
     {
         *dest++ = *src++;
     }
     return ret;
 }

 int main()
 {
     char str1[] = "abcdefffffff";
     char* str2 = "ghijk";
     my_strncpy(str1,str2,7);
     printf("%s\n",str1);
     strncpy(str1,str2,7);
     printf("%s\n",str1);
 }*/

/*char* my_strncpy(char* dest,const char* src,size_t num)
 {
     asser(dest && src);
     char* ret = dest;
     while(num && (*dest++ = *src++))
     {
        num--;
     }

     if(num)
        while(--num)
        {
            *dest++ = '\0';
        }
     return ret;
 }

 int main()
 {
     char str1[] = "abcdefffffff";
     char* str2 = "ghijk";
     my_strncpy(str1,str2,7);
     printf("%s\n",str1);
     strncpy(str1,str2,7);
     printf("%s\n",str1);
 }*/

/*int main ()
{
    char str1[20];
    char str2[20];
    strcpy (str1,"To be ");
    strcpy (str2,"or not to be");
    strncat (str1, str2, 6);
    puts (str1);
    return 0;
}*/

/*char* my_strncat(char* dest,const char* src,size_t num)
{
    asser(dest && src);
    char* ret = dest;
    while(*dest++)
    {
        ;
    }
    dest--;
    while(num--)
    {
        if(!(*dest++ = *src++))
            return ret;
    }

    *dest = '\0';
    return ret;
}

int main ()
{
    char str1[20];
    char str2[20];
    strcpy (str1,"To be ");
    strcpy (str2,"or not to be");
    my_strncat (str1, str2, 6);
    printf("%s\n",str1);
    return 0;
}*/

/*int main ()
{
    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n;
    puts ("Looking for R2 astromech droids...");
    for (n=0 ; n<3 ; n++)
        if (strncmp (str[n],"R2xx",2) == 0)
        {
            printf ("found %s\n",str[n]);
        }
    return 0; 
}*/

/*int my_strncmp (const char* dest,const char* src,size_t num)
{
    //asser(str1 && str2);
    while(*dest++ == *src++)
    {
        if(!(--num))
            return 0;
    }

    return (int)(*dest - *src);
}

int main ()
{
    char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
    int n;
    puts ("Looking for R2 astromech droids...");
    for (n=0 ; n<3 ; n++)
        if (my_strncmp (str[n],"R2xx",2) == 0)
        {
            printf ("found %s\n",str[n]);
        }
    return 0; 
}*/

/*int main ()
{
    char str[] ="This is a simple string";
    char * pch;
    pch = strstr (str,"simple");
    strncpy (pch,"sample",6);
    puts (str);
    return 0;
}*/

/*char* my_strstr(const char* dest,const char* src)
{
    //asser(dest && src);
    char* ret = (char*)dest;
    char* s1;
    char* s2;

    if(!*src)
        return (char*)dest;

    while(*ret)
    {
        s1 = ret;
        s2 = (char*)src;
        while((*s1 == *s2) && *s1 && *s2)
        {
            s1++;
            s2++;
        }
        if(!*s2)
            return ret;
        ret++;
    }
    return NULL;    
}

int main ()
{
    char str[] ="abbbcrgssgg";
    char* pch = my_strstr (str,"bbc");
    printf("%s\n",pch);
    return 0;
}*/

/*int main ()
{
    char str[] ="- This, a sample string.";
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
    return 0;
}*/

/*int main()
{
    char *p = "zhangpengwei@bitedu.tech";
    const char* sep = ".@";
    char arr[30];
    char *str = NULL;
    strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
    for(str=strtok(arr, sep); str != NULL; str=strtok(NULL, sep))
    {
        printf("%s\n", str);
    }
}*/

/*
#include <errno.h>//必须包含的头文件
int main ()
{
    FILE * pFile;
    pFile = fopen ("unexist.ent","r");
    if (pFile == NULL)
        printf ("Error opening file unexist.ent: %s\n",strerror(errno));
    //errno: Last error number
    return 0; 
}
//Edit & Run
*/

/*#include <ctype.h>
int main ()
{
    int i=0;
    char str[]="Test String.\n";
    char c;
    while (str[i])
    {
        c=str[i];
        if (isupper(c)) 
            c=tolower(c);
        putchar (c);
        i++;
    }
    return 0;
}
*/
/*
struct {
        char name[40];
        int age;
        } person, person_copy;

int main ()
{
    char myname[] = "Pierre de Fermat";
    memcpy ( person.name, myname, strlen(myname)+1 );
    person.age = 46;
    memcpy ( &person_copy, &person, sizeof(person) );
    printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );
    return 0; 
}*/

//模拟实现mencpy函数;
/*
struct {
        char name[40];
        int age;
        } person, person_copy;

void* my_memcpy(void* dest,const void* src,size_t num)
{
    //asser(dest && src);
    void* ret = dest;

    while(num--)
    {
        *(char*)dest++ = *(char*)src++;
    }
    return ret;
}

int main ()
{
    char myname[] = "Pierre de Fermat";
    my_memcpy ( person.name, myname, strlen(myname)+1 );
    person.age = 46;
    my_memcpy ( &person_copy, &person, sizeof(person) );
    printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );
    return 0;
}
*/

/*
int main ()
{
    char str[] = "memmove can be very useful......";
    memmove (str+20,str+15,11);
    puts (str);
    return 0; 
}
*/

//模拟实现memmove函数;
/*void* my_memmove(void* dest,const void* src,size_t num)
{
    //asser(dest && src);
    void* ret = dest;

    if(dest<src)//前->后
    {
        while(num--)
        {
            *(char*)dest++ = *(char*)src++;
        }
    }
    else//后->前
    {
        while(num--)
        {
            *((char*)dest + num) = *((char*)src + num);
        }
    }
    return ret;
}

int main ()
{
    char str[] = "memmove can be very useful......";
    my_memmove (str+20,str+15,11);
    puts (str);
    return 0; 
}*/


int main ()
{
    char buffer1[] = "DWgaOtP12df0";
    char buffer2[] = "DWGAOTP12DF0";
    int n;
    n=memcmp ( buffer1, buffer2, sizeof(buffer1) );
    if (n>0) 
        printf ("'%s' is greater than '%s'.\n",buffer1,buffer2);
    else 
    if (n<0) 
        printf ("'%s' is less than '%s'.\n",buffer1,buffer2);
    else 
        printf ("'%s' is the same as '%s'.\n",buffer1,buffer2);
    return 0;
}

