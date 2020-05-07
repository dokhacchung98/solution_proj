#include <iostream>
#include<algorithm>

using namespace std;
int arr[1000000];
int vl = 0;
int isFind = 0;
int n;
long long int m;
long checksum(long long int v){
    long long int tmp = 0;
    for(int i = n-1; i > 0; i--){
        if(arr[i] >= v){
            tmp += arr[i] - v;
        }else{
            break;
        }
    }
    if(tmp == m){
        vl = m;
        vl = v;
        isFind = 1;
    }else if(tmp > m){
        if(vl < v){
            vl = v;
        }
        return 0;
    }else {
        return 1;
    }
}
int main()
{
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int d = arr[0];
    int c = arr[n - 1];
    while(d < c){
        int l = (d + c)/2;
        if(checksum(l) == 1){
            c = l;
        }else {
            d = l + 1;
        }
        if(isFind == 1){
            break;
        }
    }
    cout << vl;
    return 0;
}
