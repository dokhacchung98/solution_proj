#include <iostream>

using namespace std;
int t, h, w;
char arr[102][102];
int arrTmp[102][102];
int arrSXA[10];
int arrSYA[10];
int numberSA = 0;
int arrSXI[10];
int arrSYI[10];
int numberSI = 0;
int arrSXW[10];
int arrSYW[10];
int numberSW = 0;
int check = 0;
char tmp[] = {'L','L','I','Z','Z','W','E','L','L'};
int tmpIndex = 0;
void tryMove(int y, int x){
    if(check == 1){
        return;
    }

}
int main()
{
    cin >> t;
    while(t > 0){
        numberS = 0;
        tmpIndex = 0;
        cin >> h >> w;
        for(int i = 0; i < w + 2; i++){
            arrTmp[0][i] = 1;
            arrTmp[h+1][i] = 1;
        }
        for(int i = 1; i < h + 1; i++){
            arrTmp[i][0] = 1;
            arrTmp[i][w+1] = 1;
        }
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> arr[i][j];
                arrTmp[i][j] = 0;
                if(arr[i][j] == 'A'){
                    arrSX[numberS] = j;
                    arrSY[numberS] = i;
                    numberS++;
                }
            }
        }
        for(int i = 0; i < h+2; i++){
            for(int j = 0; j < w+2; j++){
                cout << arrTmp[i][j]<< " ";
            }
            cout << endl;
        }
        if(numberS == 0){
            printf("NO");
        }else{
            for(int i = 0; i < numberS; i++){
                arrTmp[arrSY[i]][arrSX[i]] = 1;
                tryMove(arrSY[i], arrSX[i]);
                arrTmp[arrSY[i]][arrSX[i]] = 0;
            }
            if(check == 0){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
        t--;
    }
    return 0;
}
