#include <iostream>
using namespace std;
int arr[5050];
int dem = 0;
int d = 0;
int c = 0;
int m = 0;
void xoaDau(){
    d++;
    if(m == 0){
        m = c - d;
    }else{
        m--;
    }
}
void chuyenCuoi(int v){
    arr[++c] = v;
    xoaDau();
}
int main()
{
    int n, t;
    cin >> t;
    while(t > 0)
    {
        cin >> n;
        cin >> m;
        d = 0;
        c = n - 1;
        dem = 0;
        for (int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        while(1){
            int check = 1;
            for(int i = d + 1; i <= c; i++){
                if(arr[i] > arr[d]){
                    check = 0;
                    chuyenCuoi(arr[d]);
                    break;
                }
            }
            if(check == 1){
                if(m == 0){
                    break;
                }
                dem++;
                xoaDau();
            }
        }
        cout<<dem + 1<<endl;
        t--;
    }
    return 0;
}
