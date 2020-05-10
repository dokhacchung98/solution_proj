#include <iostream>

using namespace std;
long int arr[100000];
int n = -1;
int ans = -1;
int t;
void add(int number, int p){
    n++;
    for(int i = n; i > p; i--){
        arr[i] = arr[i-1];
    }
    arr[p] = number;
}
void del(int p){
    if(p == n){
        n--;
        return;
    }
    for(int i = p; i < n; i++){
        arr[i] = arr[i+1];
    }
    n--;
}
void getMedianNumber(){
    if(n == 0){
        ans = arr[0];
        n--;
        return;
    }
    if((n+1) % 2 == 0){
        int x = (n+1)/2;
        int index = arr[x] < arr[x-1] ? x : x-1;
        ans = arr[index];
        del(index);
    }else{
        int x = (n+1)/2;
        ans = arr[x];
        del(x);
    }
}
void binary(int d, int c, int v){
    if(d > c)
        return;
    int x = (c-d+1)/2;
    if(arr[x] <=v && arr[x+1] >= v){
        add(v, x+1);
        return;
    }else if(arr[x-1] <=v && arr[x] >= v){
        add(v, x);
        return;
    }else if(arr[x] < v){
        binary(x+1, c, v);
    }else{
        binary(d, x-1, v);
    }
}
int main()
{
    cin >> t;
    int tmp;
    while(t > 0){
        cin >> tmp;
        switch(tmp){
            case 0:
                t--;
                n = -1;
                break;
            case -1:
                if(n >= 0){
                    getMedianNumber();
                    cout << ans << endl;
                }
                break;
            default:
                if(n == -1 || tmp >= arr[n]){
                    n++;
                    arr[n] = tmp;
                }else if(tmp <= arr[0]){
                    add(tmp, 0);
                }else {
                    binary(0, n, tmp);
                }
        }
    }
    return 0;
}
