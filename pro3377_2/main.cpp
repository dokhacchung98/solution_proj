#include <iostream>

using namespace std;
int t;
int check = 0;
int arr[2002];
int arrTmp[2002][2002];
int n;
int v;
int d = 1;
void checkBug(int index, int type, int x){
    if(check == 1){
        return;
    }
    arr[index] = type;
    for(int i = 1; i <= arrTmp[index][0]; i++){
        int bug = arrTmp[index][i];
        if(arr[bug] == -1){
            checkBug(bug, type == 0 ? 1 : 0, index);
        }else if(bug != x && arr[bug] == type){
            check = 1;
            return;
        }
    }
}
int main()
{
    cin >> t;
    while(t > 0){
        check = 0;
        cin >> n;
        cin >> v;
        for(int i = 0; i <= n; i++){
            arr[i] = -1;
            for(int j = 0; j <= n; j++){
                arrTmp[i][j] = 0;
            }
        }
        int x, y, m;
        for(int i = 1; i <= v; i++){
            cin >> x >> y;
            m = ++arrTmp[x][0];
			arrTmp[x][m] = y;

			m = ++arrTmp[y][0];
			arrTmp[y][m] = x;
        }
        for(int i = 1; i <= n; i++)
			if(arr[i] == -1)
				checkBug(i,0, -1);
        cout << "Scenario #" << d  << ":"<< endl;
		if (check == 1) cout << "Suspicious bugs found!" << endl;
		else cout << "No suspicious bugs found!" << endl;
        t--;
        d++;
    }
    return 0;
}
