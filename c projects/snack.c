//1 for head, 2 for body up, 3 for food, 4 for body right, 5 for body down, 6 for body left, 7 for wall 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
int b[21][21]={0};
int i,j,l=0,h1=9,h2=9,t1=9,t2=9;
void dis()
{
    system("cls");
    for (i=0;i<21;i++)
    {
        for (j=0;j<21;j++)
        {
            if (b[i][j]==0) printf(". ");
            else if(b[i][j]==1) printf("H ");
            else if(b[i][j]==7) printf("w ");
            else if(b[i][j]==3) printf("O ");
            else if(b[i][j]==4 || b[i][j]==6) printf("- ");
            else if(b[i][j]==2 || b[i][j]==5) printf("| ");
        }
        printf ("\n");
    }
}
void food()
{
    int f1,f2;
    f1=rand()%19+1;
    f2=rand()%19+1;
    if(b[f1][f2]==0) b[f1][f2]=3;
    else food();
}
void tail()
{
    if (b[t1][t2]==2)
        {
            b[t1][t2]=0;
            t1--;
        }
        else if (b[t1][t2]==4)
        {
            b[t1][t2]=0;
            t2++;
        }
        else if (b[t1][t2]==5)
        {
            b[t1][t2]=0;
            t1++;
        }
        else if (b[t1][t2]==6)
        {
            b[t1][t2]=0;
            t2--;
        }
}
int run(int d)
{
    if (d==1)
    {
        if (b[h1-1][h2]==0)
        {
            b[h1][h2]=2;
            b[h1-1][h2]=1;
            h1--;
            tail();
        }
        else if (b[h1-1][h2]==3)
        {
            
            b[h1][h2]=2;
            b[h1-1][h2]=1;
            h1--;
            l++;
            food();
        }
        else
        {
            return 0;
        }
        return 1;
    }
    else if (d==2)
    {
        if (b[h1][h2+1]==0)
        {
            b[h1][h2]=4;
            b[h1][h2+1]=1;
            h2++;
            tail();
        }
        else if (b[h1][h2+1]==3)
        {
            
            b[h1][h2]=4;
            b[h1][h2+1]=1;
            h2++;
            l++;
            food();
        }
        else
        {
            return 0;
        }
        return 1;
    }
    else if (d==3)
    {
        if (b[h1+1][h2]==0)
        {
            b[h1][h2]=5;
            b[h1+1][h2]=1;
            h1++;
            tail();
        }
        else if (b[h1+1][h2]==3)
        {
            
            b[h1][h2]=5;
            b[h1+1][h2]=1;
            h1++;
            l++;
            food();
        }
        else
        {
            return 0;
        }
        return 1;
    }
    else if (d==4)
    {
        if (b[h1][h2-1]==0)
        {
            b[h1][h2]=6;
            b[h1][h2-1]=1;
            h2--;
            tail();
        }
        else if (b[h1][h2-1]==3)
        {
            
            b[h1][h2]=6;
            b[h1][h2-1]=1;
            h2--;
            l++;
            food();
        }
        else
        {
            return 0;
        }
        return 1;
    }
}
int main()
{
    int d1=1,t=1,a;
    for(i=0;i<21;i++) 
    {
        b[0][i]=7;
        b[20][i]=7;
        b[i][0]=7;
        b[i][20]=7;
    }
    srand(time(NULL));
    food();
    while(t==1)
    {
        a=200;
        for (i=0;i<20;i++)
        {
            a-=10;
            if ((GetAsyncKeyState('W') & 0x8000) && d1!=3)
            {
                d1=1;
                Sleep(a);
                break;
            }
            else if ((GetAsyncKeyState('A') & 0x8000) && d1!=2) 
            {
                d1=4;
                Sleep(a);
                break;
            }
            else if ((GetAsyncKeyState('S') & 0x8000) && d1!=1) 
            {
                d1=3;
                Sleep(a);
                break;
            }
            else if ((GetAsyncKeyState('D') & 0x8000) && d1!=4) 
            {
                d1=2;
                Sleep(a);
                break;
            }
            Sleep(10);
        }
        dis();
        t=run(d1);
        if(l==361) break;
    }
    if(l==361) printf("Maximun score! \nyou win %d",l*10);
    else printf("Game over!!!\nYour score=%d",l*10);
    printf("\n\n\n\n\n\n\n\n\n");
    getchar();
}