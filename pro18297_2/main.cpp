#include <iostream>

using namespace std;
int n, t, d, c;
int arr[30];
int gt[30][30];
long long getMax(int a, int b){
    return a > b ? a : b;
}
long long getMin(int a, int b){
    return a < b ? a : b;
}
long long play(int d, int c){
    if(d > c){
        return 0;
    }
    if(gt[d][c] != -1){
        return gt[d][c];
    }
    return gt[d][c] = getMax(arr[d] + getMax(play(d+2, c), play(d+1, c-1)), arr[c] + getMax(play(d, c-2), play(d+1, c-1)));
}
long long play2(int d, int c){
    if(d > c){
        return 0;
    }
    if(gt[d][c] != -1){
        return gt[d][c];
    }
    return gt[d][c] = getMax(arr[d] + getMin(play2(d+2, c), play2(d+1, c-1)), arr[c] + getMin(play2(d, c-2), play2(d+1, c-1)));
}
int main()
{
    cin >> t;
    while(t > 0){
        cin >> n;
        d = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            for(int j = 0; j<n; j++){
                gt[i][j] = -1;
            }
        }
        long long v1 = play(0, n - 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j<n; j++){
                gt[i][j] = -1;
            }
        }
        cout << v1 << " ";
        long long v = play2(0, n - 1);
        cout << v << endl;
        t--;
    }
    return 0;
}
