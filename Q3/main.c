#include <stdio.h>
#include <stdlib.h>
/*
RIGHT =4
DOWN = 3
LEFT = 2
UP = 1
*/
int solution =0;
char stack[100];
int top=-1;
void push(char c)
    {
        printf("%c pushed onto stack\n",c);
        stack[++top]=c;
    }
char pop()
{
    if(top==-1)
    {
        printf("No solution is found");
        exit(0);
    }
    printf("%c popped from stack\n",stack[top]);
    return stack[top--];

}
/*void move()
{
    if(i==9&&j==9)
    {
        printf("Solution found\n");
        break;
    }
    //checks right move
    if(j<9&&a[i][j+1]==1)
    {
        push('r');
        j++;
    }

    //checks down move
    else if(i<9&&a[i+1][j]==1)
    {
        push('d');
        i++;
    }
    //checks left move
     else if(i>0&&a[i-1][j]==1)
    {
        push('l');
        i--;
    }
    //checks up move
     else if(j>0&&a[i][j-1]==1)
    {
        push('u');
        j--;
    }

    else
    {
        char temp=pop();
        if(temp=='r')
            j--;
        else if(temp=='d')
            i--;
        else if(temp=='l')
            j++;
        else if(temp=='u')
            i++;

    }

}*/
void print()
{
    int i=0;
    for(i=0;i<=top;i++)
        printf("%c\n",stack[i]);
}
int main()
{

 int a[][10]={{1,1,1,1,1,1,1,0,0,0},
            {1,0,1,1,0,0,0,0,0,0},
            {1,1,0,0,1,1,0,0,0,0},
            {1,0,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1},
            {0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,1,0,0,1,1,1},
            {0,0,0,0,1,1,1,1,0,1},
            {0,0,0,1,1,1,1,1,0,1}};

/*
int a[][10]={{1,1,1,1,1,1,1,0,0,0},
            {1,0,1,1,0,0,0,0,0,0},
            {1,1,0,0,1,1,0,0,0,0},
            {1,0,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1,1,1,1},
            {0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,1,0,0,0,1,1},
            {0,0,0,0,1,1,1,1,0,1},
            {0,0,0,1,1,1,1,1,0,1}};
*/

    int i=0,j=0, k=0, l=0;
    a[i][j]++;
    while(1)
    {
         if(i==9&&j==9)
    {
        printf("Solution found\n");
        print();
        for(k=0;k<10;k++)
        {
            for(l=0;l<10;l++)
                printf("%d ",a[k][l]);
            printf("\n");
        }
        break;
    }
    //checks right move
    if(j<9&&a[i][j+1]==1)
    {
        push('r');
        j++;
        a[i][j]++;
    }

    //checks down move
    else if(i<9&&a[i+1][j]==1)
    {
        push('d');
        i++;
        a[i][j]++;
    }
    //checks left move
     else if(i>0&&a[i][j-1]==1)
    {
        push('l');
        j--;
        a[i][j]++;
    }
    //checks up move
     else if(j>0&&a[i-1][j ]==1)
    {
        push('u');
        i--;
        a[i][j]++;
    }

    else
    {
        char temp=pop();
        if(temp=='r')
            j--;
        if(temp=='d')
            i--;
        if(temp=='l')
            j++;
        if(temp=='u')
            i++;
         a[i][j]++;

    }
    }
}
