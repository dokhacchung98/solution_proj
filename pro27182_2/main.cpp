#include <iostream>

using namespace std;
int arr[9][9];
int t;
int isSoduku = 0;
int num = 1;
int isValidate(int i, int j){
    for(int x = 0; x < 8; x++){
        if(arr[x][j] == arr[i][j] && x != i){
            return 0;
        }
        if(arr[i][x] == arr[i][j] && x != j){
            return 0;
        }
    }
    int x1 = j/4;
    int y1 = i/4;
    int d = 0;
    for(int i1=0; i1<4; i1++){
        for(int j1=0; j1<4; j1++){
            if(arr[i1+y1*4][j1+x1*4] == arr[i][j]){
                if(i1 + y1*4 == i && j1 + x1*4 == j){
                    d++;
                }else if(i1 + y1*4 == i || j1 + x1*4 == j){
                    return 0;
                }else{
                    d++;
                }
                if(d > 2)
                    return 0;
            }
        }
    }
    return 1;
}
void check(int i, int j){
//    if(isSoduku == 1){
//        return;
//    }
    if(arr[i][j] == 0){
        for(int x = 0; x < 8; x++){
            arr[i][j] = x+1;
            check(i, j);
            arr[i][j] = 0;
        }
    }else{
        int tmp = isValidate(i, j);
        if(tmp == 1){
            if(j < 7){
                check(i, j+1);
            }else{
                if(i < 7){
                    check(i+1, 0);
                }else{
                    isSoduku = 1;
                    cout << "Test case #"<< num <<": YES" << endl;
                    for(int k=0; k<8; k++){
                        for(int g=0; g<8; g++){
                            cout << arr[k][g] << " ";
                        }
                        cout << endl;
                    }
                    return;
                }
            }
        }else{
            return;
        }
    }
}
int main()
{
    cin >> t;
    int num = 1;
    while(t > 0){
        isSoduku = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cin >> arr[i][j];
            }
        }
        check(0, 0);
        if(isSoduku == 0){
            cout << "Test case #"<< num <<": NO" << endl;
        }
        num++;
        t--;
    }
    return 0;
}


/*
4
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
*/

