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
    //���ļ�
    pFile = fopen ("myfile.txt","w");
    //�ļ�����
    if (pFile!=NULL)
    {
        fputs ("fopen example",pFile);
        //�ر��ļ�
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

//fputc���ַ�bit����д���ļ�test.txt��
/*
int main()
{
    //�򿪻��ߴ���test.txt�ļ�;
    FILE* fp = fopen("test.txt","w");
    if(fp == NULL)
    {
        //���ļ�ʧ��;
        printf("%s\n",strerror(errno));
        return 0;
    }
    //fputc����
    fputc('b',fp);
    fputc('i',fp);
    fputc('t',fp);

    //�ر��ļ�;
    fclose(fp);
    fp = NULL;
    return 0;
}
*/

//fputc���ַ�bit����д���׼����豸����Ļ����
/*
int main()
{
    //fputc����
    fputc('b',stdout);
    fputc('i',stdout);
    fputc('t',stdout);
    return 0;
}
*/

/*
//fgetc���ļ�test.txt�ļ��ж�ȡ�ַ�
int main()
{
    //�򿪻��ߴ���test.txt�ļ�;
    FILE* fp = fopen("test.txt","r");
    if(fp == NULL)
    {
        //���ļ�ʧ��;
        printf("%s\n",strerror(errno));
        return 0;
    }
    //fgetc����
    char ch = fgetc(fp);
    printf("%c",ch);
    ch = fgetc(fp);
    printf("%c",ch);
    ch = fgetc(fp);
    printf("%c",ch);

    //�ر��ļ�;
    fclose(fp);
    fp = NULL;
    return 0;
}
*/

/*
//fgetc�ӱ�׼����ӿڣ����̣���ȡ�ַ�
int main()
{
    int ch = fgetc(stdin);
    fputc(ch,stdout);
    return 0;
}
*/

/*
//4.2.1��fputs���ַ��ַ���hello worldд���ļ�test.txt��
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
//4.2.1��fputs���ַ��ַ���hello worldд���׼����ӿڣ���Ļ��
int main()
{
    char ch[] = "hello world1";
    fputs("hello world\n",stdout);
    fputs(ch,stdout);
    return 0;
}
*/

/*
//4.2.3��fgets���ļ�test1.txt�ļ��ж�ȡ�ַ���
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
//fgets���ļ���׼�����豸�����̣���ȡ�ַ���
int main()
{
    char buf[100] = {0};
    fgets(buf,100,stdin);//�Ӽ��̶����ַ���;
    fputs(buf,stdout);//���������ַ����������Ļ;
    return 0;
}
*/

/*
//ʹ��fprintf���ṹ���е����ݱ��浽test2.txt�ļ���
struct S
{
    char ch[30];
    int n;
    double f;
};
int main()
{
    struct S s = {"����",24,95.6435};
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
//4.3.2��fprintf�ѽṹ��������������׼����ӿڣ���Ļ��
struct S
{
    char ch[30];
    int n;
    double f;
};
int main()
{
    struct S s = {"����",24,95.6};
    fprintf(stdout,"%s %d %f",s.ch,s.n,s.f);
    return 0;
}
*/

/*
//4.3.3��fscanf�ļ�test3.txt�ļ��ж�ȡ�ַ���
struct S
{
    char ch[30];
    int n;
    double f;
};
int main()
{
    struct S s = {"����",24,95.6};
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
//4.3.4��fscanf���ļ���׼�����豸�����̣���ȡ
int main()
{
    char buf[1024];
    fscanf(stdin,"%s",buf);
    fprintf(stdout,"%s",buf);
    return 0;
}
*/

/*
//4.4.1��ʹ��fwrite���ṹ���е����ݱ��浽test3.txt�ļ���
struct S
{
    char name[30];
    int age;
    double f;
};

int main()
{
    struct S s = {"����",43,78.65};
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
//4.4.2��fread������test3.txt�ļ��ж�ȡ����������
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
    fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
    fclose(pf);
    pf = NULL;
    return 0;
}
*/

/*
//�ı��ļ�
#include <stdio.h>
#include <stdlib.h>
int main(void) 
{
    int c; // ע�⣺int����char��Ҫ����EOF
    FILE* fp = fopen("test.txt", "r");
    if(!fp) 
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    //fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
    while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
    { 
        putchar(c);
    }
    //�ж���ʲôԭ�������
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
    FILE *fp = fopen("test.bin", "wb"); // �����ö�����ģʽ
    fwrite(a, sizeof *a, SIZE, fp); // д double ������
    fclose(fp);
    double b[SIZE];
    fp = fopen("test.bin","rb");
    size_t ret_code = fread(b, sizeof *b, SIZE, fp); // �� double ������
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
//VS2013 WIN10��������
int main()
{
    FILE*pf = fopen("test.txt", "w");
    fputs("abcdef", pf);//�Ƚ�����������������
    printf("˯��10��-�Ѿ�д�����ˣ���test.txt�ļ��������ļ�û������\n");
    Sleep(10000);
    printf("ˢ�»�����\n");
    fflush(pf);//ˢ�»�����ʱ���Ž����������������д���ļ������̣�
    //ע��fflush �ڸ߰汾��VS�ϲ���ʹ����
    printf("��˯��10��-��ʱ���ٴδ�test.txt�ļ����ļ���������\n");
    Sleep(10000);
    fclose(pf);
    //ע��fclose�ڹر��ļ���ʱ��Ҳ��ˢ�»�����
    pf = NULL;
    return 0;
}