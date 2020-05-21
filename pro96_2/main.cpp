#include<iostream>
using namespace std;

char arr[29][29];
int tmp[28][28];
int ans;
int row , col,desi,sori,desj,sorj;

void tryMove(int i,int j,int cur_tmp){
    if (cur_tmp>=ans) return ;
    if(cur_tmp>=tmp[i][j]) return ;
    else tmp[i][j]=cur_tmp;
    if(arr[i+1][j]=='D' || arr[i][j+1]=='D' || arr[i-1][j]=='D' || arr[i][j-1]=='D'){
        ans=cur_tmp;
        return ;
    }
    if(arr[i+1][j]!='X') tryMove(i+1,j,(cur_tmp+arr[i+1][j]-48));
    if(arr[i][j+1]!='X') tryMove(i,j+1,(cur_tmp+arr[i][j+1]-48));
    if(arr[i-1][j]!='X') tryMove(i-1,j,(cur_tmp+arr[i-1][j]-48));
    if(arr[i][j-1]!='X') tryMove(i,j-1,(cur_tmp+arr[i][j-1]-48));
    return ;
}

int main(){
    int i,j;
    int temp1,temp2;
    while(1){
        ans=1<<20;
        for(i=0;i<28;i++) for(j=0;j<28;j++) tmp[i][j]=1<<20;
        cin >> col >> row;
        if(row==0 && col==0) break;
        getchar();
        temp1=row+1;
        temp2=col+1;
        for(i=0;i<=temp1;i++){
            arr[i][0]='X';
            arr[i][temp2]='X';
        }
        for(i=0;i<=temp2;i++){
            arr[temp1][i]='X';
            arr[0][i]='X';
        }

        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                cin >> arr[i][j];
                if(arr[i][j]=='S') {
                    sori=i;
                    sorj=j;
                }
                if(arr[i][j]=='D'){
                    desi=i;
                    desj=j;
                }
            }
            getchar();
        }

        tryMove(sori,sorj,0);
        cout << ans << endl;
    }
    return 0;
}
