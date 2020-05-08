#include <iostream>

using namespace std;
int n, m;
int arr[10000][10000];
int tmp[10000];
int checkNodeEmpty = 0;
int tmpNodeTop = -1;
int checkBound = 0;
int as = 0;
void checkNode(int k){
    if(checkNodeEmpty == 1 || checkBound == 1){
        return;
    }
    tmp[k] = 1;
    for(int i=0; i<n; i++){
        if(arr[k][i] == 1 && i != k && tmp[i] == 0){
            arr[k][i] = 0;
            arr[i][k] = 0;
            checkNode(i);
        }else if(i != k && arr[k][i] == 1 && tmp[i] == 1){
            checkBound = 1;
            return;
        }
    }
}

int main()
{
    cin >> n;
    cin >> m;
    for(int i = 0; i< n;i++){
        tmp[i] = 0;
        for(int j=0; j< n; j++){
            arr[i][j] = 0;
        }
    }
    for(int i=0; i<m; i++){
        int t1, t2;
        cin >> t1;
        cin >> t2;
        arr[t2-1][t1-1] = 1;
        arr[t1-1][t2-1] = 1;
    }
    checkNode(0);
    for(int i=0; i<n; i++){
        if(tmp[i] == 0){
            checkNodeEmpty = 1;
            break;
        }
    }
    if(checkBound == 1 || checkNodeEmpty == 1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}
/*
5 4
5 4
2 1
1 5
2 3
1 3
*/
