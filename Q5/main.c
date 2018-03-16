#include <stdio.h>
#include <stdlib.h>
int *tempstack;
int *mainstack;
int topt=-1,topm=-1;

void pusht(int x)
{
    topt++;
    tempstack[topt]=x;
}
void pushm(int x)
{
    topm++;
    mainstack[topm]=x;


}
int popt()
{
    return tempstack[topt--];

}
int popm()
{
    return mainstack[topm--];
}
void enqueue(int x)
{
    pusht(x);
}
int dequeue()
{
    int x,y;
    while(topt!=-1)
    {
        x=popt();
        pushm(x);
    }
    x=popm();
    while(topm!=-1)
    {
       y=popm();
       pusht(y);
    }
    return x;
}
void printm()
{
    int i;
    printf("MAINSTACK\n");
    for(i=topm;i>=0;i--)
    {
        printf("%d\n",mainstack[i]);

    }
}
void printt()
{
    int i;
    printf("TEMPSTACK\n");
    for(i=topt;i>=0;i--)
    {
        printf("%d\n",tempstack[i]);

    }
}
int main()
{

   tempstack=(int *)malloc(100*sizeof(int));
   mainstack=(int *)malloc(100*sizeof(int));
   enqueue(1);
   enqueue(2);
   enqueue(3);
   enqueue(4);
   enqueue(5);
   printm();
   printt();

   printf("%d\n",dequeue());

   printm();
   printt();


}
