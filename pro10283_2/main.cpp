#include<iostream>
using namespace std;

const char arrTmp[] = {'A', 'L','L','I','Z','Z','W','E','L','L'};

int  h, w;
int  ans;
char arr[105][105];
int tmp[105][105];

int drow[8] = {-1,-1,0,1,1, 1, 0,-1};
int dcol[8] = { 0, 1,1,1,0,-1,-1,-1};

void tryMove(int row, int col, int index)
{
    if(ans == 1){
        return;
    }
	if(index == 9)
	{
		ans = 1;
		return;
	}

	for(int i = 0; i < 8; i++)
	{
		int r = row + drow[i];
		int c = col + dcol[i];

		if (r >= 0 && r < h && c >= 0 && c < w &&
			!tmp[r][c] && arr[r][c] == arrTmp[index+1])
		{
			tmp[r][c] = 1;
			tryMove(r, c, index+1);
			tmp[r][c] = 0;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++)
	{
		ans = 0;
		cin >> h >> w;
		for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
                tmp[i][j] = false;
            }
		}

		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
				if(arr[i][j] == 'A')
				{
					tmp[i][j] = 1;
					tryMove(i, j, 0);
					tmp[i][j] = 0;

					if(ans) break;
				}

			if(ans) break;
		}
		if(ans == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
