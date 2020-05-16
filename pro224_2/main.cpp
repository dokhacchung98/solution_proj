#include <stdio.h>

int visited[7][8];
int arr[7][8];
int tmpDomino[7][7];
int result = 0;
int dx[2] = {0, 1};
int dy[2] = {1, 0};
void tryMove(int x, int y)
{
	if(x==7)
	{
		result++;
		return;
	}
	if(visited[x][y]==0)
	{
		int one, two;
		one = arr[x][y];
		for(int i=0; i<2; i++)
		{
			int tempx = x + dx[i];
			int tempy = y + dy[i];
			if(tempx>=0&&tempx<7&&tempy>=0&&tempy<8&&visited[tempx][tempy]==0)
			{
				two = arr[tempx][tempy];
				if(one<=two && tmpDomino[one][two])
				{
					tmpDomino[one][two] = 0;
					visited[x][y] = visited[tempx][tempy] = 1;
					if(y<7)tryMove(x, y+1);
					else tryMove(x+1, 0);
					visited[x][y] = visited[tempx][tempy] = 0;
					tmpDomino[one][two] = 1;
				}
				else if(tmpDomino[two][one])
				{
					tmpDomino[two][one] = 0;
					visited[x][y] = visited[tempx][tempy] = 1;
					if(y<7)tryMove(x, y+1);
					else tryMove(x+1, 0);
					visited[x][y] = visited[tempx][tempy] = 0;
					tmpDomino[two][one] = 1;
				}
			}
		}
	}
	else
	{
		if(y<7)tryMove(x, y+1);
		else tryMove(x+1, 0);
	}
}

int main()
{
	int number_test, i, j, test;
	for(int i=0; i<=6; i++)
		for(int j=i; j<=6; j++)
			tmpDomino[i][j] = 1;
	scanf("%d", &number_test);
	for(test=0; test<number_test; test++)
	{
		for(i=0; i<7; i++)
			for(j=0; j<8; j++)
				scanf("%d", &arr[i][j]);
		result = 0;
		tryMove(0, 0);
		printf("%d\n", result);
	}

}
