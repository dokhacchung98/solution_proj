#include <iostream>

using namespace std;
int arr[10][10];
int flag;

int check_blocks(int x, int y)
{
    int startx = x/4;
    int starty = y/4; int end_x = startx*4 + 4; int end_y = starty*4 + 4;
    int F[9];
    for(int ii=0; ii<9; ii++)F[ii] = 0;
    for(int i=startx*4; i<end_x; i++)
        for(int j=starty*4; j<end_y; j++)
        {
            if(arr[i][j] == 0)continue;
            F[arr[i][j]]++;
            if(F[arr[i][j]]>2)
                return 1;
        }
        return 0;
}
int check_row_col(int index_x, int index_y)
{
    int F_row[10];
    int F_col[10];
    for(int i=0; i<9; i++)F_row[i] = F_col[i] =0;
    for(int i=0; i<8; i++){
        if(arr[index_x][i]==0)continue;
        F_row[arr[index_x][i]]++;
        if(F_row[arr[index_x][i]]>1)
            return 1;
    }
    for(int i=0; i<8; i++){
        if(arr[i][index_y]==0)continue;
        F_col[arr[i][index_y]]++;
        if(F_col[arr[i][index_y]]>1)
            return 1;
    }
    return 0;
}
int check_full_row_col()
{
    for(int i=0; i<8; i++)
        if(check_row_col(i,i)==1)return 1;
    return 0;
}
void sodoku(int x, int y)
{
    if(x>=8)
    {
        flag = 1;
        return;
    }
    if(arr[x][y]!=0)
    {
        if(y<7)sodoku(x, y+1);
        else sodoku(x+1, 0);
    }
    else
    {
        for(int i=1; i<=8; i++)
        {
            arr[x][y] = i;
            if(!check_row_col(x, y)&&!check_blocks(x, y))
            {
                if(y<7)sodoku(x, y+1);
                else sodoku(x+1, 0);
            }
            if(flag==1)return;
            arr[x][y] = 0;
        }
    }
}

int main()
{
    int nTestCase;
    scanf("%d", &nTestCase);
    for(int test=1; test<=nTestCase; test++)
    {
        int startx = -1, starty = -1;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
            {
                scanf("%d", &arr[i][j]);
                if(arr[i][j]==0&&startx==-1)
                {
                    startx = i;
                    starty = j;
                }
            }
            flag = 0;
            if(!check_blocks(0,0)&&!check_blocks(0,4)&&!check_blocks(4,0)&&!check_blocks(4,4)&&!check_full_row_col())
            {
                sodoku(startx, starty);
                if(flag)
                {
                    printf("Test case #%d: YES\n", test);
                    for(int i=0; i<8; i++)
                    {
                        for(int j=0; j<8; j++)
                            printf("%d ", arr[i][j]);
                        printf("\n");
                    }
                }
                else printf("Test case #%d: NO\n", test);
            }
            else printf("Test case #%d: NO\n", test);
    }
    return 0;
}


/*
5
8 0 0 0 0 0 0 0
0 0 0 0 0 0 6 0
0 0 0 3 0 0 0 0
0 0 5 0 0 0 0 0
0 0 0 0 0 4 0 0
0 0 0 0 2 0 0 0
0 7 0 0 0 0 0 0
0 0 0 0 0 0 0 1

0 5 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 3 6 0 0
0 0 0 0 0 4 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

1 2 3 4 5 6 7 0
5 6 2 1 3 4 0 7
6 5 0 7 2 1 3 4
3 4 7 8 6 5 2 1
2 1 5 6 8 7 4 3
4 3 6 5 7 8 1 2
0 7 1 2 4 3 5 6
7 0 4 3 1 2 6 5

1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

8 1 2 4 3 5 7 6
1 2 3 5 4 7 6 8
4 6 7 3 5 1 8 2
6 8 5 7 1 2 3 4
2 3 1 6 8 4 5 7
7 4 6 8 2 3 1 5
5 7 4 1 6 8 2 3
3 5 8 2 7 6 4 1
*/

