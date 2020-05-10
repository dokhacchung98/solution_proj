#include <iostream>

using namespace std;
int te, h, w;
int arr[110][110];
int v = 0;
int l = 0;
int t = 0;
int r = 0;
int main()
{
    cin >> te;
    while(te > 0){
        cin >> h >> w;
        v = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 1; i < h; i++){
            for(int j = 0; j < w; j++){
                l = 0;
                t = 0;
                r = 0;
                if(j > 0)
                    l = arr[i-1][j-1];
                t = arr[i-1][j];
                if(j < w-1)
                    r = arr[i-1][j+1];
                int m = l;
                if(t > m)
                    m = t;
                if(r > m)
                    m = r;
                arr[i][j] += m;
            }
        }
        for(int i = 0; i < w; i++){
            if(arr[h-1][i]>v){
                v = arr[h-1][i];
            }
        }
        cout << v << endl;
        te--;
    }
    return 0;
}
