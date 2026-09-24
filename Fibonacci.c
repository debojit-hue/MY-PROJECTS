#include <stdio.h>
int main()
{
    int a=0,b=1,c,t;
    printf ("enter the number of terms ");
    scanf("%d",&c);
    for (int i=1;i<=c;i++)
    {
        printf (" %d",a);
        t=a+b;
        a=b;
        b=t;
    }
}