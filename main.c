#include"header.h"
extern int count;
char str[100],New[100],stack[100];
int main()
{
        printf("enter infix statement:\n");
	fgets(str,100,stdin);
	if(str[strlen(str)-1]=='\n');
	  str[strlen(str)-1]='\0';
	postfix(str,New);
	if(count!=0)
	 printf("invalid expression");
	else
	puts(New);
}
