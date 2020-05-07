#include <iostream>

using namespace std;
int n, t, d, c;
int arr[30];
int s = 0;
int tmp = 0;

void play(){
    if(d > c){
        return;
    }
    int l = c - d + 1;
    if(l % 2 == 0){
        if(arr[d] > arr[c]){
            s += arr[d];
            d++;
        }else {
            s += arr[c];
            c--;
        }
    }else {
        if(arr[d] < arr[c]){
            d++;
        }else {
            c--;
        }
    }
    play();
}
int play2(int d, int c){
    if(d > c){
        return 0;
    }
    int tong = 0;
    int l = c - d + 1;
    if(l % 2 == 0){
        int s1 = arr[d] + play2(d + 1, c);
        int s2 = arr[c] + play2(d, c - 1);
        cout << "asd:" << s1 << " - " << s2<<endl;
        if(s1 > s2){
            tong = s1;
        }else {
            tong = s2;
        }
    }else {
        if(arr[d] > arr[c]){
            d++;
        }else {
            c--;
        }
    }
    return tong;
}
int main()
{
    cin >> t;
    while(t > 0){
        cin >> n;
        d = 0;
        s = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        c = n - 1;
        play();
        cout << s << "\t";
        s = 0;
        c = n - 1;
        d = 0;
        int l = play2(0, n - 1);
        cout << l;
        t--;
    }
    return 0;
}
