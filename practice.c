#include <stdio.h>
int main()
{
    int i,j;
    int a1[2][2];
    int a2[2][2];
    int a3[2][2];
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("enter the number for first matrix\n");
            scanf("%d",&a1[i][j]);   
        }
    }
    for(i=0;i<2;i++)
    {
        for (j=0;j<2;j++)
        {
            a2[j][i]=a1[i][j];
        }
    }
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf ("%d",a1[i][j]);
            printf (" ");   
        }
        printf ("\n");
    }
    printf("\n");
    for (i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf ("%d",a2[i][j]);
            printf (" ");   
        }
        printf ("\n");
    }
}