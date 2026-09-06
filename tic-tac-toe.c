#include <stdio.h>
int b[3][3]={0};int i,j;
void dis()
{
    printf('\n');
    for(i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (b[i][j]==0) printf(". ");
            else if (b[i][j]==1) printf("X ");
            else if (b[i][j]==2) printf("O ");
        }
        printf("\n");
    }
}
int cheak()
{
    int c=0;
    for (i=0;i<3;i++)
    {
        if (b[0][i]!=0 && b[0][i]==b[1][i] && b[1][i]==b[2][i]) c=b[0][i];
    }
    for (i=0;i<3;i++)
    {
        if (b[i][0]!=0 && b[i][0]==b[i][1] && b[i][1]==b[i][2]) c=b[i][0];
    }
    if (b[0][0]!=0 && b[1][1]==b[2][2] && b[0][0]==b[1][1]) c=b[0][0];
    if (b[2][0]!=0 && b[2][0]==b[1][1] && b[1][1]==b[0][2]) c=b[2][0];
    return c;
}
void turn1()
{
    int r,c;
    printf("Enter the Row number: \n");
    scanf("%d",&r);
    printf("Enter the Column number: \n");
    scanf("%d",&c);
    c-=1;
    r-=1;
    if ((r<3 && r>=0)&&(c<3 && c>=0))
    {
        if (b[r][c]!=0)
        {
            printf("Grid is already occupied try again.....\n");
            turn1();
        }
        else b[r][c]=1;
    }
    else
    {
        printf ("Invalid row or column number \n Try again....\n");
        turn1();
    }
}
void turn2()
{
    int r,c;
    printf("Enter the Row number: \n");
    scanf("%d",&r);
    printf("Enter the Column number: \n");
    scanf("%d",&c);
    r-=1;
    c-=1;
    if ((r<3 && r>=0)&&(c<3 && c>=0))
    {
        if (b[r][c]!=0)
        {
            printf("Grid is already occupied try again.....\n");
            turn2();
        }
        else b[r][c]=2;
    }
    else
    {
        printf ("Invalid row or column number \n Try again....\n");
        turn2();
    }
}
int main()
{
    int w=0,cu=0;
    while (w==0)
    {
        dis();
        printf("1st player turn:(X)\n");
        turn1 ();
        cu++;
        w=cheak ();
        if (w==1) break;
        dis();
        if (cu==9) break;
        printf("2nd player turn:(O)\n");
        turn2();
        cu++;
        w=cheak ();
        if (w==2) break;
    }  
    if (w==1) printf("\nPlayer 1 wins!!! ");
    else if (w==2) printf ("\nPlayer 2 wins!!! ");
    else printf("\nDraw "); 
    dis();  
}