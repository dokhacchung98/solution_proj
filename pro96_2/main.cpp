#include <iostream>

using namespace std;
char arr[30][30];
int hasMove[30][30];
int w;
int h;
int x;
int y;
int t = -1;
int tmp = 0;
int drow[] = {-1,0,1, 0};
int dcol[] = { 0,1,0,-1};
void tryMove(int i, int j){
    if(arr[i][j] == 'D'){
        if(tmp < t || t == -1){
            t = tmp;
        }
        return;
    }
    for(int g = 0; g<4; g++){
        if(arr[i + drow[g]][j+dcol[g]] != 'X' && hasMove[i + drow[g]][j+dcol[g]] == 0){
            int k = 0;
            if(arr[i + drow[g]][j+dcol[g]] != 'D')
            k = arr[i + drow[g]][j+dcol[g]] - 48;
            if(tmp + k > t && t != -1){
                return;
            }
            tmp += k;
            hasMove[i + drow[g]][j+dcol[g]] = 1;
            tryMove(i + drow[g], j+dcol[g]);
            hasMove[i + drow[g]][j+dcol[g]] = 0;
            tmp -= k;
        }
    }
}
int main()
{
    while(1){
        cin >> w;
        cin >> h;
        tmp = 0;
        t = -1;
        if(w == 0 && h == 0){
            break;
        }
        if(w == 0 || h == 0){
            cout<<"0\n";
        }else {
            int checkS = 0;
            int checkD = 0;
            for(int i = 0; i < w + 2; i++){
                arr[0][i] = 'X';
                arr[h+1][i] = 'X';
            }
            for(int i = 1; i < h + 1; i++){
                arr[i][0] = 'X';
                arr[i][w+1] = 'X';
            }
            for(int i = 1; i < h + 1; i++){
                for(int j = 1; j < w + 1; j++){
                    cin >> arr[i][j];
                    if(arr[i][j] == 'S'){
                        checkS = 1;
                        x = j;
                        y = i;
                        arr[i][j] = 'X';
                    }else if(arr[i][j] == 'D'){
                        checkD = 1;
                    }
                }
            }
            if(checkS == 0 || checkD == 0)
                cout << "0" << endl;
            else{
                tryMove(y, x);
                if(t == -1)
                    cout << "0" << endl;
                else
                    cout << t <<endl;
            }
        }
    }
    return 0;
}


/*
20 20
7448822082943S812608
19410745968127836544
79476935490731581276
88699210476042515010
80373022571779474473
63070235345957968468
10803035186620419899
40396552852609319752
93267692148984371304
16640425426879478834
42497743988347139696
38128409472303376648
35207600535665538310
14435160499317200275
61301550872530577086
35596883798567616583
36176073856513654431
58830131939958802283
09960228422528540234
2854431034062719741D

0 0

*/
