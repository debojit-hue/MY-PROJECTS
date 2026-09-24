#include <stdio.h>
#include <math.h>
int main()
{
    int n,dup,d,c=0;double s=0;
    printf("enter the number\n");
    scanf("%d",&n);
    dup=n;
    while(n!=0)
    {
        n/=10;
        c++;
    }
    n=dup;
    while(n!=0)
    {
        d=n%10;
        s+=pow(d,c);
        n/=10;
    }
    if (dup==s)
    printf("it is armstrong number");
    else
    printf("it is not an armstrong number");
}
