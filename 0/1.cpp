#include <stdio.h>
#include <stdlib.h>//system
#include <string.h>
#include <ctype.h>//c库函数int isspasce(int c)检查所传字符是否是空白字符，标准空白字符：“”“空格\t水平制表符\n换行符\v垂直制表符\f换页符\r回车符”

void Ccount(char File[])//字符数计算函数
{
int count=0;//计数器
char ch=' ';//空
FILE *f_read=fopen(File,"r");
if(f_read==NULL){printf("Error,Retry again!\n");return ;}
while((ch=fgetc(f_read))!=EOF)
{if(isspace(ch)==0)count++;}
fclose(f_read);
printf("character=%d\n",count);
system("pause");
}

void Wcount(char File[])//单词数计算函数
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

void Lcount(char File[]){//行数计算函数
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
printf("*************\nc:字符数统计;\nw:单词数统计;\nl:行数统计;  \nq:退出程序;  \n*************\n");
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
