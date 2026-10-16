#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void postfix(char *str,char *new);
int priority(char ch);
char pop();
void push(char ch);
int i,j;
char str[100],new[100];
char stack[100];
int top=-1,count;
int main()
{
        printf("enter infix statement:\n");
	fgets(str,20,stdin);
	if(str[strlen(str)-1]=='\n');
	  str[strlen(str)-1]='\0';
	postfix(str,new);
	if(count!=0)
	 printf("invalid expression");
	else
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
			if((str[i]=='(')||(str[i]=='[')||(str[i]=='{'))
			{ 
				push(str[i]);
				count++;
			}
			else if(str[i]==')')
			{
			
				while(pop()!='(');
			        if(stack[top+1]!='(')
                                { printf("invalid expression");
                                        exit(0);
                                }
			        count--;
                        }
			else if(str[i]=='}')
			{
				while(pop()!='{')
				if(stack[top+1]!='{')
				{ printf("invalid expression");
					exit(0);
				}
				count--;
				
			}
			else if(str[i]==']')
			{
				while(pop()!='[')
                                if(stack[top+1]!='[')
                                { printf("invalid expression");
                                        exit(0);
                                }

				count--;

			}
			else
			{
			     if((stack[top]=='(')||(stack[top]=='[')||(stack[top]=='{'))
			     {
				    push(str[i]);
			     }
			      else if(priority(stack[top])>priority(str[i]))
			      {
				while((stack[top]!='(')&&(stack[top]!='[')&&(stack[top]!='{')&&(priority(stack[top])>priority(str[i])))
			          {		pop();
					if(top<0)
						break;
				}
				     push(str[i]);

			      }
			      else if(priority(stack[top])==priority(str[i]))
			      {
				     pop();
				     push(str[i]);
			      }
			     else
			     {
				     push(str[i]);
			     }
			}}
	}
	while(top>-1)
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
       	if((stack[top]!='(')&&(stack[top]!='[')&&(stack[top]!='{'))
	{
	new[j]=temp;
	j++; 
	}
	top--;
	return temp;
}
int priority(char ch)
{
        if(ch=='^')
			 return 3;
	else if((ch=='*')||(ch=='/')||(ch=='%'))
			 return 2;
       	else if((ch=='+')||(ch=='-'))
			 return 1;
	else
		return 0; 
}
