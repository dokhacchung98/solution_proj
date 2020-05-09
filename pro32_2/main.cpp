#include <iostream>
#include <string.h>
using namespace std;
char arr[1000000000];
int length = 0;
int n = 0;
char tmp[100000];
int getL(char x[]){
    return strlen(x);
}
void run(){
    for(int i = 0; i<=length-n; i++){
        if(arr[i] == tmp[0]){
            int check = 0;
            for(int j = 1; j < n; j++){
                if(arr[i+j] != tmp[j]){
                    check = 1;
                    break;
                }
            }
            if(check == 0){
                cout << i << endl;
            }
        }
    }
}
int main()
{
    while(cin >> n){
        cin >> tmp;
        cin >> arr;
        length = getL(arr);
        run();
        cout<<endl;
    }
    return 0;
}
