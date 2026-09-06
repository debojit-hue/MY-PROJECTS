#include <stdio.h>
int main()
{
    int n,d=1,du,s;
    printf( "enter the number: \n");
    scanf("%d",&n);
    du=n;
    s=n*n;
    while(n!=0)
    {
        d*=10;
        n/=10;
    }
    s%=d;
    if (s==du)
    {
        printf("it is an automorphuc number");
    }
    else
    {
        printf ("it is not");
    }
}