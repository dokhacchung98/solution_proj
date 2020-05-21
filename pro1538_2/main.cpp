#include <iostream>
using namespace std;
int arr[100][100];
int tmp[100][100];
int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[8] = {2, 1, -2, -1, 2, 1, -2, -1};

int result = 0, row, col;

void TryMove(int x, int y, int dem)
{
	tmp[x][y] = 1;
	if(dem>result)result = dem;
	for(int i=0; i<8; i++)
	{
		int tempx = x + dx[i];
		int tempy = y + dy[i];
		if(tempx>=0&&tempx<row&&tempy>=0&&tempy<10&&tmp[tempx][tempy]==0&&arr[tempx][tempy]==1)
			TryMove(tempx, tempy, dem+1);
	}
	tmp[x][y] = 0;
}

int main()
{
	int test=0;
	while(++test)
	{
		int start, end;
		cin >> row;
		if(row==0)break;
		int sum = 0, start_point;
		for(int i=0; i<row; i++)
		{
		    cin >> start >> end;
			if(start+end>col)col = start+end;
			if(i==0)start_point = start;
			sum += end;
			for(int index=start; index<start+end; index++)
				arr[i][index] = 1;
		}
		result = 0;
		TryMove(0, start_point, 1);
		if(sum-result!=1){
                cout << "Case "<< test <<", "<< sum - result <<" squares can not be reached."<< endl;
        }
		else{
            cout << "Case "<< test <<", "<< sum - result <<" square can not be reached."<<endl;
		}
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)arr[i][j] = 0;
	}
	return 0;
}
