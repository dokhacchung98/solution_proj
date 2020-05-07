#include <iostream>

using namespace std;
int arr[500];
int n, s;
int check = 0;
int tong(){
    int tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += arr[i];
    }
    return tmp;
}
void changeOperator(int index){
    if(check == 0){
        arr[index] *= -1;
        int s1 = tong();
        if(s1 == s){
            check = 1;
            for(int i = 0; i < n; i++){
                if(arr[i]>0 && i > 0){
                    cout << "+" << arr[i];
                }else {
                    cout << arr[i];
                }
            }
            return;
        }
        if(index < n - 1){
            changeOperator(index + 1);
            arr[index] *= -1;
            changeOperator(index + 1);
        }
    }
}
int main()
{
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    if(tong() < s){
        cout << "Impossible";
    }
    changeOperator(1);

    if(check == 0){
        cout << "Impossible";
    }
    return 0;
}
