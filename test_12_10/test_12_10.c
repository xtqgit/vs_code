#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>


/*
struct _iobuf
{
    char *_ptr;
    int  _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};
typedef struct _iobuf FILE;

int main()
{
    return 0;
}
*/

/* fopen fclose example */
/*
#include <stdio.h>
int main ()
{
    FILE * pFile;
    //打开文件
    pFile = fopen ("myfile.txt","w");
    //文件操作
    if (pFile!=NULL)
    {
        fputs ("fopen example",pFile);
        //关闭文件
        fclose (pFile);
    }
    return 0;
}
*/

/*
struct S
{
    int n;
    float scorce;
    char arr[10];
};

int main()
{
    struct S s = {100,3.14,"abcdef"};
    struct S temp = {0};
    char buf[1024] = {0};

    sprintf(buf,"%d %f %s",s.n,s.scorce,s.arr);
    printf("%s\n",buf);
    sscanf(buf,"%d %f %s",&(temp.n),&(temp.scorce),temp.arr);
    printf("%d %f %s\n",temp.n,temp.scorce,temp.arr);

    return 0;
}*/

//fputc把字符bit依次写入文件test.txt中
/*
int main()
{
    //打开或者创建test.txt文件;
    FILE* fp = fopen("test.txt","w");
    if(fp == NULL)
    {
        //打开文件失败;
        printf("%s\n",strerror(errno));
        return 0;
    }
    //fputc函数
    fputc('b',fp);
    fputc('i',fp);
    fputc('t',fp);

    //关闭文件;
    fclose(fp);
    fp = NULL;
    return 0;
}
*/

//fputc把字符bit依次写入标准输出设备（屏幕）中
/*
int main()
{
    //fputc函数
    fputc('b',stdout);
    fputc('i',stdout);
    fputc('t',stdout);
    return 0;
}
*/

/*
//fgetc从文件test.txt文件中读取字符
int main()
{
    //打开或者创建test.txt文件;
    FILE* fp = fopen("test.txt","r");
    if(fp == NULL)
    {
        //打开文件失败;
        printf("%s\n",strerror(errno));
        return 0;
    }
    //fgetc函数
    char ch = fgetc(fp);
    printf("%c",ch);
    ch = fgetc(fp);
    printf("%c",ch);
    ch = fgetc(fp);
    printf("%c",ch);

    //关闭文件;
    fclose(fp);
    fp = NULL;
    return 0;
}
*/

/*
//fgetc从标准输入接口（键盘）读取字符
int main()
{
    int ch = fgetc(stdin);
    fputc(ch,stdout);
    return 0;
}
*/

/*
//4.2.1、fputs把字符字符串hello world写入文件test.txt中
int main()
{
    char ch[] = "hello world1";
    FILE* fp = fopen("test1.txt","w");
    if(fp==NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    fputs("hello world\n",fp);
    fputs(ch,fp);

    fclose(fp);
    fp = NULL;
    return 0;
}
*/

/*
//4.2.1、fputs把字符字符串hello world写入标准输出接口（屏幕）
int main()
{
    char ch[] = "hello world1";
    fputs("hello world\n",stdout);
    fputs(ch,stdout);
    return 0;
}
*/

/*
//4.2.3、fgets从文件test1.txt文件中读取字符串
int main()
{
    char buf[30] = {0};
    FILE* fp = fopen("test1.txt","r");
    if(fp == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    fgets(buf,30,fp);
    printf("%s",buf);
    fgets(buf,30,fp);
    printf("%s",buf);

    fclose(fp);
    fp = NULL;
    return 0;
}
*/

/*
//fgets从文件标准输入设备（键盘）读取字符串
int main()
{
    char buf[100] = {0};
    fgets(buf,100,stdin);//从键盘读入字符串;
    fputs(buf,stdout);//将读到的字符串输出到屏幕;
    return 0;
}
*/

/*
//使用fprintf将结构体中的数据保存到test2.txt文件中
struct S
{
    char ch[30];
    int n;
    double f;
};
int main()
{
    struct S s = {"张三",24,95.6435};
    FILE* fp = fopen("test.txt","w");
    if(fp == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }

    fprintf(fp,"%s %d %f",s.ch,s.n,s.f);
    fclose(fp);
    fp = NULL;
    return 0;
}
*/

/*
//4.3.2、fprintf把结构体的数据输出到标准输出接口（屏幕）
struct S
{
    char ch[30];
    int n;
    double f;
};
int main()
{
    struct S s = {"张三",24,95.6};
    fprintf(stdout,"%s %d %f",s.ch,s.n,s.f);
    return 0;
}
*/

/*
//4.3.3、fscanf文件test3.txt文件中读取字符串
struct S
{
    char ch[30];
    int n;
    double f;
};
int main()
{
    struct S s = {"张三",24,95.6};
    struct S temp = {0};
    FILE* fp = fopen("test2.txt","r+");
    if(fp == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    fscanf(fp,"%s %d %lf",temp.ch,&(temp.n),&(temp.f));
    printf("%s %d %f",temp.ch,temp.n,temp.f);
    fclose(fp);
    fp = NULL;
    return 0;
}
*/

/*
//4.3.4、fscanf从文件标准输入设备（键盘）读取
int main()
{
    char buf[1024];
    fscanf(stdin,"%s",buf);
    fprintf(stdout,"%s",buf);
    return 0;
}
*/

/*
//4.4.1、使用fwrite将结构体中的数据保存到test3.txt文件中
struct S
{
    char name[30];
    int age;
    double f;
};

int main()
{
    struct S s = {"李四",43,78.65};
    FILE* fp = fopen("test3.txt","w");
    if(fp == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    fwrite(&s,sizeof(struct S),1,fp);
    fclose(fp);
    fp = NULL;
    return 0;
}
*/

/*
//4.4.2、fread函数从test3.txt文件中读取二进制数据
struct S
{
    char name[30];
    int age;
    double f;
};

int main()
{
    struct S buf;
    FILE* fp = fopen("test3.txt","r");
    if(fp == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    fread(&buf,sizeof(struct S),1,fp);
    printf("%s %d %lf",buf.name,buf.age,buf.f);
    fclose(fp);
    fp = NULL;
    return 0;
}
*/


/* fseek example */
/*
#include <stdio.h>
int main ()
{
    FILE * pFile;
    pFile = fopen ( "example.txt" , "wb" );
    fputs ( "This is an apple." , pFile );
    fseek ( pFile , 9 , SEEK_SET );
    fputs ( " sam" , pFile );
    fclose ( pFile );
    return 0;
}
*/

/*
//ftell
#include <stdio.h>
int main ()
{
    FILE * pFile;
    long size;
    pFile = fopen ("myfile.txt","rb");
    if (pFile==NULL) 
        perror ("Error opening file");
    else
    {
        fseek (pFile, 0, SEEK_END); // non-portable
        size=ftell (pFile);
        fclose (pFile);
        printf ("Size of myfile.txt: %ld bytes.\n",size);
    }
    return 0;
}
*/

/* rewind example */
/*
#include <stdio.h>
int main ()
{
    int n;
    FILE* pFile;
    char buffer [27];
    pFile = fopen ("myfile.txt","w+");
    for ( n='A' ; n<='Z' ; n++)
    fputc ( n, pFile);
    rewind (pFile);
    fread (buffer,1,26,pFile);
    fclose (pFile);
    buffer[26]='\0';
    puts (buffer);
    return 0;
}
*/

/*
#include <stdio.h>
int main()
{
    int a = 10000;
    FILE* pf = fopen("test.txt", "wb");
    fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
    fclose(pf);
    pf = NULL;
    return 0;
}
*/

/*
//文本文件
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
    int c; // 注意：int，非char，要求处理EOF
    FILE* fp = fopen("test.txt", "r");
    if(!fp) 
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    //fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
    while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
    { 
        putchar(c);
    }
    //判断是什么原因结束的
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");
    fclose(fp);
    fp = NULL;
}
*/

/*
#include <stdio.h>
enum 
{
    SIZE = 5
};
int main(void) 
{
    double a[SIZE] = {1.,2.,3.,4.,5.};
    FILE *fp = fopen("test.bin", "wb"); // 必须用二进制模式
    fwrite(a, sizeof *a, SIZE, fp); // 写 double 的数组
    fclose(fp);
    double b[SIZE];
    fp = fopen("test.bin","rb");
    size_t ret_code = fread(b, sizeof *b, SIZE, fp); // 读 double 的数组
    if(ret_code == SIZE)
    {
        puts("Array read successfully, contents: ");
        for(int n = 0; n < SIZE; ++n)
            printf("%f ", b[n]);
        putchar('\n');
    } 
    else 
    { // error handling
        if (feof(fp))
            printf("Error reading test.bin: unexpected end of file\n");
        else
        if (ferror(fp)) 
        {
            perror("Error reading test.bin");
        }
    }
    fclose(fp);
}
*/

#include <stdio.h>
#include <windows.h>
//VS2013 WIN10环境测试
int main()
{
    FILE*pf = fopen("test.txt", "w");
    fputs("abcdef", pf);//先将代码放在输出缓冲区
    printf("睡眠10秒-已经写数据了，打开test.txt文件，发现文件没有内容\n");
    Sleep(10000);
    printf("刷新缓冲区\n");
    fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件（磁盘）
    //注：fflush 在高版本的VS上不能使用了
    printf("再睡眠10秒-此时，再次打开test.txt文件，文件有内容了\n");
    Sleep(10000);
    fclose(pf);
    //注：fclose在关闭文件的时候，也会刷新缓冲区
    pf = NULL;
    return 0;
}