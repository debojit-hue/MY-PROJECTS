#include <stdio.h>
int main()
{
    int n,d,s=0,f=1,du;
    printf("Enter the number: \n");
    scanf("%d",&n);
    du=n;
    while (n!=0)
    {
        d=n%10;
        n/=10;
        for (int i=1;i<=d;i++)
        {
            f*=i;
        }
        s+=f;
        f=1;
    }
    if (s==du)
    {
        printf ("it is a strong number");
    }
    else
    {
        printf("its not a strong number");
    }
}