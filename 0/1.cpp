#include <stdio.h>
#include <stdlib.h>//system
#include <string.h>
#include <ctype.h>//c�⺯��int isspasce(int c)��������ַ��Ƿ��ǿհ��ַ�����׼�հ��ַ����������ո�\tˮƽ�Ʊ��\n���з�\v��ֱ�Ʊ��\f��ҳ��\r�س�����

void Ccount(char File[])//�ַ������㺯��
{
int count=0;//������
char ch=' ';//��
FILE *f_read=fopen(File,"r");
if(f_read==NULL){printf("Error,Retry again!\n");return ;}
while((ch=fgetc(f_read))!=EOF)
{if(isspace(ch)==0)count++;}
fclose(f_read);
printf("character=%d\n",count);
system("pause");
}

void Wcount(char File[])//���������㺯��
{
int count=0;
char ch=' ';
FILE *f_read=fopen(File,"r");
if(f_read==NULL){
printf("Error,Retry again!\n");
return ;
}
while((ch=fgetc(f_read))!=EOF)
{
while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
ch=fgetc(f_read);
count++;
}

fclose(f_read);
printf("word=%d\n",count);
system("pause");
}

void Lcount(char File[]){//�������㺯��
int count=0;
char ch[1024];
int status=0;
FILE *f_read=fopen(File,"r");
if(f_read==NULL){
printf("Error,Retry again!\n");
return ;
}
while(!feof(f_read)){
fgets(ch,1024,f_read);
if(status==0&&ch[0]=='\0')break;
else status=1;
count++;
}
fclose(f_read);
printf("line=%d\n",count);
system("pause");
}


int main()
{
   // int test=1;
    char func;
    char File[50];
    while(1)
    {
printf("(Enter s for description list.)");
printf("input your instruction:wc.exe-");
scanf(" %c",&func);
if(func=='s'){
printf("*************\nc:�ַ���ͳ��;\nw:������ͳ��;\nl:����ͳ��;  \nq:�˳�����;  \n*************\n");
break;
}
printf("Enter the address of the file:");
scanf("%s",File);
switch(func){
case 'c': Ccount(File);break;
case 'w': Wcount(File);break;
case 'l': Lcount(File);break;
case 'q': return 0;
default : printf("Error Retry again!\n");break;
}
}
}
