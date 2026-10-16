#include<stdio.h>
#include<string.h>
#include"header.h"
extern int j;
extern char stack[100],New[100];
int top=-1;
void push(char ch)
{
	stack[++top]=ch;
}
char pop()
{
	char temp;
	temp=stack[top];
       	if((stack[top]!='(')&&(stack[top]!='[')&&(stack[top]!='{'))
	{
	New[j]=temp;
	j++; 
	}
	top--;
	return temp;
}
