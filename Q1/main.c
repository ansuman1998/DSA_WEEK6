#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
int stack[100];
int top=-1;
void push(int x)
{
    printf("Pushed into stack %d\n",x);
    stack[++top]=x;
}
int pop()
{
    printf("Popped from stack %d\n", stack[top]);
    return stack[top--];
}
int main()
{
    int n,maxarea=-1,area=-1,height,leftindex, rightindex;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    int i;
    printf("%d\n",n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("Scanning complete\n");
    i=0;
    while(i<n)
    {
        if(top==-1||a[i]>=a[stack[top]])
            {
                push(i);
                i++;
                printf("i incremented to %d\n", i);
            }

        else
        {
            while(top>-1&&a[stack[top]]>a[i])
            {
                height=a[pop()];
                if(top==-1)
                    leftindex=-1;
                else
                    leftindex=stack[top];
                rightindex=i;
                printf("Height %d, leftindex %d, rightindex %d\n", height,leftindex,rightindex);
                area=height*(rightindex-leftindex-1);
                if(area>maxarea)
                    maxarea=area;

            }
        }

    }

    while(top!=-1)
    {
        height=a[pop()];
                if(top==-1)
                    leftindex=-1;
                else
                    leftindex=stack[top];
                rightindex=i;
                area=height*(rightindex-leftindex-1);
                if(area>maxarea)
                    maxarea=area;
    }

    printf("%d\n",maxarea);


}
