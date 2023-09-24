

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct stack {
	int top;
	int item[MAX];
	}stk;
void create(stk *ps)
	 {
		(ps)->top=-1;
	 }
int isempty(stk *ps)
	 {
		 if((ps)->top==-1)
			 return(1);
		 else
			 return(0);
	 }
int isfull(stk *ps)
	 {
		  if((ps)->top==MAX-1)
			  return(1);
		  else
			  return(0);
	 }
int push( stk *ps,int x)
	  {
			if(isfull(ps))
			  {
			    return 0;
			  }
			else
			  {
				 (ps)->item[++(ps)->top]=x;
				 return 1;
			  }
	  }
int pop(stk *ps, int *flag)
	  {
		  if(isempty(ps))
			 {
				 *flag=0;
			 }
		  else
			  {
				*flag=1;
				 return((ps)->item[(ps)->top--]);
			  }
	  }
int top(stk *ps, int *flag)
	  {
		  if(isempty(ps))
			 {
				 *flag=0;
			 }
		  else
			  {
				*flag=1;
				 return((ps)->item[(ps)->top]);
			  }
	  }
void display(stk *ps)
	  {
		 int i;
		 if(ps->top==-1)
			 printf("Stack is empty\n");
		 else
			 {
				printf("\nCurrent Stack is:\n");
for(i=0;i<=ps->top;i++)
				printf("%d\t",ps->item[i]);
			 }
	  }
int main()
  {
	int op,x,ch,r;
	stk s;
  	create(&s);
	while(1)
	 {
	printf("\nMENU\n");
	printf("1: isempty\n2: push\n3: pop\n4:top\n5: display\n6: quit\n");
	printf("Enter your option\n");
	scanf("%d",&op);
	switch(op)
		{
			case 1: 	x=isempty(&s);
						if(x)
							printf("Stack is empty\n");
						else
							printf("Stack is not empty\n");
						break;
			case 2:  printf("Enter value to be pushed\n");
						scanf(" %d",&ch);
						r=push(&s,ch);
						if(r)
                            printf("Item %d is pushed\n",ch);
                        else
                            printf("Stack is full\n");
						break;
			case 3: 	x=pop(&s,&r);
						if(r)
							printf("Poped item is %d\n",x);
                        else
                            printf("Stack is empty\n");
						break;
			case 4:  x=top(&s,&r);
						if(r)
							printf("Toped item is %d\n",x);
                        else
                            printf("Stack is empty\n");
						break;
            case 5:  display(&s);
						break;
			case 6:	 exit(0);
	  }
	 }
  }
