#include <iostream>

using namespace std;
int n, m, c;
char arr[43][43];
int tmp[43][43];
int check = 0;
int arrSX[40];
int arrSY[40];
int numberS = 0;
void tryMore(int i, int j, int c2){
    if(check == 1){
        return;
    }
    if(arr[i][j] == 's'){
        c2 -= 2;
        if(c2 < 0){
            return;
        }
    }
    if(arr[i][j] == 'x'){
        check = 1;
        return;
    }
    if(arr[i-1][j] != '#' && tmp[i-1][j] != 1){
        tmp[i-1][j] = 1;
        tryMore(i-1, j, c2);
        tmp[i-1][j] = 0;
    }
    if(arr[i+1][j] != '#' && tmp[i+1][j] != 1){
        tmp[i+1][j] = 1;
        tryMore(i+1, j, c2);
        tmp[i+1][j] = 0;
    }
    if(arr[i][j-1] != '#' && tmp[i][j-1] != 1){
        tmp[i][j-1] = 1;
        tryMore(i, j-1, c2);
        tmp[i][j-1] = 0;
    }
    if(arr[i][j+1] != '#' && tmp[i][j+1] != 1){
        tmp[i][j+1] = 1;
        tryMore(i, j+1, c2);
        tmp[i][j+1] = 0;
    }
}
int main()
{
    cin >> n;
    cin >> m;
    cin >> c;
    for(int i = 0; i < n + 2; i++){
        arr[i][0] = '#';
        arr[i][m+1] = '#';
    }
    for(int i = 1; i <= m+2; i++){
        arr[0][i] = '#';
        arr[n+1][i] = '#';
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            tmp[i][j] = 0;
            if(arr[i][j] == '@'){
                tmp[i][j] = 1;
                arrSX[numberS] = j;
                arrSY[numberS] = i;
                numberS++;
            }
        }
    }
//    cout<<endl;
//    for(int i = 0; i < n+2; i++){
//        for(int j = 0; j < m+2; j++){
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    for(int i = 0; i < numberS; i++){
        if(check == 0){
            tryMore(arrSY[i], arrSX[i], c);
        }
    }
    if(check == 0){
        cout << "IMPOSSIBLE" << endl;
    }else {
        cout << "SUCCESS" << endl;
    }
    return 0;
}
/*
6
5
2
# @ # # @
# . s # #
@ . . # #
# s s . .
# # # s .
# @ . x #
*/

/*
4 6 6
# @ # # # #
# s . . . #
. # # s s .
# x s . . #
*/
