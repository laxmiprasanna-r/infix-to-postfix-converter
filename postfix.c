#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void postfix(char *str,char *new);
int priority(char ch);
char pop();
void push(char ch);
int i,j=0;
char str[20],new[20];
char stack[10];
int top=-1;
int main()
{
        printf("enter infix statement");
	fgets(str,20,stdin);
	postfix(str,new);
	puts(new);
}
void postfix(char *str,char *new)
{
	for(i=0;str[i];i++)
	{
		if(((str[i]>='A')&&(str[i]<='Z'))||((str[i]>='a')&&(str[i]<='z')))
		{
			new[j]=str[i];
			j++;
		}
		else
		{
			if(str[i]=='(')
			{ 
				push(str[i]);
			}
			else if(str[i]==')')
			{
				while(pop()!='(');
			        top--;
			}
			else
			{
			     if((stack[top])=='(')
			     {
				    push(str[i]);
			     }
			      else if(priority(stack[top])>priority(str[i]))
			      {
				      while((pop()!='(')&&(priority(stack[top])>priority(str[i])))
				      {
					      if(top<0)
						      break;
				      }
				      push(str[i]);
				    
			      }
			     else
			     {
				     push(str[i]);
			     }
			}}
	}
	

        while(top<0)
		pop();
}
void push(char ch)
{
	stack[++top]=ch;
}
char pop()
{
	char temp;
	temp=stack[top];
	if(temp!='(')
	new[j++]=temp; 
	top--;
	return temp;
}
int priority(char ch)
{
  switch(ch)
  {
	  case 1:if(ch=='^')
			 return 3;
		 break;
	  case 2:if((ch=='*')||(ch=='/'))
			 return 2;
		 break;
	  case 3:if((ch=='+')||(ch=='-'))
			 return 1;
		 break;
	  case 4:exit(0);
  }
}
