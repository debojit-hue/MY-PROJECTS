#include <stdio.h>
int main ()
{
    int c=0,a;
    printf ("enter a number\n");
    scanf("%d",&a);
    for (int i=2;i<=a/2;i++)
    {
        if (a%i==0)
        {
            c++;
            break;
        }
    }
    if (c==0)
    {
        printf("prime number");
    }
    else if (a==1)
    {
        printf("1 is not a prime number");
    }
    else
    {
        printf("it's not a prime number");
    }
}
