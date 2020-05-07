#include <iostream>

using namespace std;
int arr[1000];
int arrStack[1000];
int p1 = -1;
int lasted = 0;
int main()
{
    int n;
    while(1){
        cin >> n;
        int check = 1;
        if(n == 0){
            break;
        }
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            if(arr[i] - lasted == 1){
                lasted = arr[i];
            }else{
                p1++;
                arrStack[p1] = arr[i];
            }
            while(1){
                if(p1 >= 0 && arrStack[p1] - lasted == 1){
                    lasted = arrStack[p1];
                    p1--;
                    if(p1<0){
                        break;
                    }
                }else{
                    break;
                }
            }
            if(i == n-1 && p1 >= 0){
                check = 0;
            }
        }
        if(check == 1){
            cout<<"yes"<<endl;
        }else {
            cout<<"no"<<endl;
        }
        lasted = 0;
        p1 = -1;
    }
    return 0;
}
