#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int p =1000000007;
long long int factorial[100000];
int print(int *a, int n)
{
    int i;
    for(i=97;i<123;i++)
        printf("%d ",a[i]);
    printf("\n");
}

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
long long int modularexponent(long long int x)
{
    long long int y=p-2, res=1;
    x=x%p;
    while(y>0)
    {
        if(y%2==1)
        {
            res=res*x;
            res=res%p;
            //printf("Result is %lld\n", res);
        }
        y=y>>1;
        x=(x*x);
        //printf("X is %lld p is %lld\n",x,p);
        x=x%p;
       // printf("X after modular is %lld\n",x);

    }
    return res;
}
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
long long int func(char *s, int low, int high)
{
    int ch[257],i;
    for(i=0;i<257;i++)
        ch[i]=0;
    for(i=low;i<=high;i++)
        ch[s[i]]++;
    //print(ch,257);
    long long int num=1;
    long long int den=1;
    long long int odds=0;
    long long int nonzero=0;
    long long int temp=1;
    for(i=97;i<=122;i++)
    {

        nonzero+=ch[i]/2;
        temp=(temp*factorial[ch[i]/2])%p;


        if(ch[i]%2!=0)
            odds++;

    }
        //printf("%lld %lld %lld\n",den,odds,nonzero);
        num=factorial[nonzero];
        //printf("%lld\n",num);
        //printf("%lld\n",temp);
        den=modularexponent(temp);
        num=(num*den)%p;
        //printf("%lld\n",den);
        if(odds>0)
        return (num*odds)%p;
        else
        return num%p;
}
int main()
{
    char s[]="madamimadam";

    long long int i;
    long long int n=strlen(s);
    factorial[0]=1;
    for(i=1;i<100000;i++)
        factorial[i]=(factorial[i-1]*i)%p;
    int a=1, b=11;
    int q=100000;
    /*while(q!=0)
        {
            int a=(rand()+1)%n;
            int b=(rand()+a)%n;
            func(s,a-1,b-1);
            q--;
        }*/
    printf("%lld\n",func(s,a-1,b-1));
}
