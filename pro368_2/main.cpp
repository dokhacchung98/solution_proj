#include <iostream>
#define INT_MAX 2147483647

using namespace std;
int t;
int p;
int n = 0;
long m = 0;
int arr[1000][1000];
int tmp[1000];
long shortPath[1000];
long ans;
int getIndex(){
    int mi = INT_MAX;
    int index;
    for(int i = 0; i < n; i++){
        if(tmp[i] == 0 && shortPath[i] < mi){
            mi = shortPath[i];
            index = i;
        }
    }
    return index;
}
int main()
{
    cin >> t;
    while(t > 0){
        ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                arr[i][j] = 0;
            }
        }
        cin >> p;
        cin >> n;
        cin >> m;
        int a, b, c;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c;
            arr[a-1][b-1] = c;
            arr[b-1][a-1] = c;
        }
        for(int i = 0; i < n; i++){
            tmp[i] = 0;
            shortPath[i] = INT_MAX;
        }
        shortPath[0] = 0;
        for(int i = 0; i < n; i++){
            int u = getIndex();
            ans += shortPath[u];
            tmp[u] = 1;
            for(int j = 0; j < n; j++){
                if(arr[u][j] != 0 && tmp[j] == 0 && arr[u][j] < shortPath[j]){
                    shortPath[j] = arr[u][j];
                }
            }
        }
        cout << ans * p << endl;
        t--;
    }
    return 0;
}
