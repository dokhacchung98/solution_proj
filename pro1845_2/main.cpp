#include <iostream>
using namespace std;

const int MAX_INT = 1 << 20;

int n, m, e, t;
int arr[105][105];
int tmp[105];
int key[105];

int getIndexMin()
{
	int idm = 0, _min = MAX_INT;
	for(int i = 1; i <= n; i++){
        if(tmp[i] == 0 && key[i] < _min)
		{
			_min = key[i];
			idm  = i;
		}
	}
	return idm;
}

void Dijkstra(int start)
{
	int dem = 0;
	for(int i = 1; i <= n; i++)
	{
		tmp[i] = 0;
		key[i] = MAX_INT;
	}

	key[start] = 0;
	while(dem < n)
	{
		int idmin = getIndexMin();
		tmp[idmin] = 1;
		dem++;
		for(int i = 1; i <= n; i++){
            if(tmp[i] == 0 && arr[idmin][i] > 0 &&
				key[idmin] + arr[idmin][i] < key[i]){
                    key[i] = key[idmin] + arr[idmin][i];
				}
		}
	}
}

int main()
{
	cin >> n;
	cin >> e;
	cin >> t;
	cin >> m;
	for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = 0;
		}
	}

	int a, b, d;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> d;
		arr[b][a] = d;
	}
	Dijkstra(e);
	int ans = 0;
	for(int i = 1; i <= n; i++){
        if(key[i] <= t) ans++;
	}
	cout << ans << endl;
	return 0;
}
