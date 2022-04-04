#include <stdio.h>
#include <stdlib.h>
char b[9];
void player1(int a[],int b[]);
void player2(int a[],int b[]);
int print();
int check(int a[]);
int play();
int main()
{
    int n;
    system("cls");
    printf("Menu\n\n\n\n");
    printf("1:Play\n2:Exit\n\n\n");
    scanf("%d",&n);
    if (n==1)
        play();
    if (n==2)
        exit(0);
    else
        main();
    return 0;
}

int play()
{
    int a[9]= {0,0,0,0,0,0,0,0,0};
    int b[9]= {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    int i,c;
    system("cls");
    printf("\nPlayer 1 : O\n");
    printf("Player 2 : X\n\n\n");
    printf("\nPositions:\n");
    printf("\n\n\n\n    \t1  |  2  |  3\n    \t--------------\n    \t4  |  5  |  6\n    \t--------------\n    \t7  |  8  |  9\n\n\n\n");
    for (i=0; i<9; i++)
    {
        if(i%2==0)
            player1(a,b);
        else
            player2(a,b);
        system("cls");
        printf("\nPositions:\n");
        printf("\n\n\n\n    \t1  |  2  |  3\n    \t--------------\n    \t4  |  5  |  6\n    \t--------------\n    \t7  |  8  |  9\n\n\n\n");
        printf("\n\n\n\n    \t%c  |  %c  |  %c\n    \t--------------\n    \t%c  |  %c  |  %c\n    \t--------------\n    \t%c  |  %c  |  %c\n\n\n\n",b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8]);

        if(i>=4)
        {
            c=check(a);
            if(c==1)
                play();
            if(c==2)
                exit(0);
            if(c!=0)
            {
                system("cls");
                print();
            }

        }
    }
    return 0;
}

void player1(int a[],int b[])
{
    int p,x;
    printf("0: Reset\n\n\n");
    printf("\t\tEnter position for O\n");
    scanf("%d",&p);
    if(p==0)
        main();
    if (p>=1 && p<=9)
    {
        if (a[p-1]==0)
        {
            a[p-1]=1;
            b[p-1]='O';
        }
        else
            player1(a,b);
    }

    else
        player1(a,b);
}

void player2(int a[],int b[])
{
    int p,x;
    printf("0: Reset\n\n\n");
    printf("\t\tEnter position for X\n");
    scanf("%d",&p);
    if(p==0)
        main();
    if (p>=1 && p<=9)
    {
        if (a[p-1]==0)
        {
            a[p-1]=2;
            b[p-1]='X';
        }
        else
            player2(a,b);
    }
    else
        player2(a,b);
}

int check(int a[])
{
    int i=0;
    if(a[0]*a[1]*a[2]==1||a[3]*a[4]*a[5]==1||a[6]*a[7]*a[8]==1||a[0]*a[3]*a[6]==1||a[1]*a[4]*a[7]==1||a[2]*a[5]*a[8]==1||a[0]*a[4]*a[8]==1||a[6]*a[4]*a[2]==1)
    {
        printf("\n\n\t\t\tO wins!!!");
        i=print();
    }
    if(a[0]*a[1]*a[2]==8||a[3]*a[4]*a[5]==8||a[6]*a[7]*a[8]==8||a[0]*a[3]*a[6]==8||a[1]*a[4]*a[7]==8||a[2]*a[5]*a[8]==8||a[0]*a[4]*a[8]==8||a[6]*a[4]*a[2]==8)
    {
        printf("\n\n\t\t\tX wins!!!");
        i=print();
    }
    if(a[0]!=0&&a[1]!=0&&a[2]!=0&&a[3]!=0&&a[4]!=0&&a[5]!=0&&a[6]!=0&&a[7]!=0&&a[8]!=0)
    {
        printf("\n\n\t\t\tDraw!!!");
        i=print();
    }
    return i;
}

int print()
{
    int p=0;
    printf("\n\n\n\n 1:Retry");
    printf("\n 2:Exit\n\n");
    scanf("%d",&p);
    return p;
}
