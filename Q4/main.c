#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *operatorstack;
int topo=-1;
char *resultstack;
int topr=-1;
void pusho(char c)
{
    operatorstack[++topo]=c;
    printf("Pushed into Operator stack %c\n",c);
}
char popo()
{
    printf("Popped from Operator stack %c\n",operatorstack[topo]);
    return operatorstack[topo--];
}
void pushr(char c)
{
    resultstack[++topr]=c;
    printf("Pushed into result stack %c\n",c);
}
char popr()
{
    printf("Popped from result stack\n",resultstack[topr]);
    return resultstack[topr--];
}
int priority(char c)
{
    if(c=='/')
        return 4;
    else if(c=='*')
        return 3;
    else if(c=='+')
        return 2;
    else if(c=='-')
        return 1;
    else if(c=='('||c==')')
        return 0;
}
int main()
{
    char ch[100];
    char temp;
    scanf("%s", ch);
    int i;
    int n=strlen(ch);
    operatorstack = (char *)malloc(100*sizeof(char));
    resultstack = (char *)malloc(100*sizeof(char));
    for(i=0;i<n;i++){
        if(isdigit(ch[i]))
            {
                pushr(ch[i]);
                printf("TOPR is %d just by digit\n", topr);
            }
        else if(ch[i]=='(')
                    pusho(ch[i]);
        else if(ch[i]==')')
        {
            while(topo>=0)
            {
                temp=popo();
                if(temp=='(')
                    {   printf("First captured, should fucking exit the loop\n");
                        break;
                    }
                else
                    pushr(temp);
            }
                    //pushr(temp);
             printf("TOPR is %d by brackety stuff\n", topr);
        }
        else
        {
            while(topo>=0 &&  !(priority(ch[i])>priority(operatorstack[topo])))
            {
                temp=popo();
                pushr(temp);

            }
            printf("TOPR is %d by operator stuff\n", topr);
            pusho(ch[i]);
        }
    }

    while(topo>=0)
    {
        temp=popo();
        pushr(temp);
    }
    printf("TOPO %d TOPR %d\n", topo, topr);
    for(i=0;i<=topr;i++)
        printf("%c",resultstack[i]);
    printf("\n");

}
