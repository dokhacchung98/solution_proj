#include <iostream>

using namespace std;
char arr[2000]={};
char arrStack[2001];
int p = 0;
int dem = 0;
int index = 0;
int main()
{

    while(1){
        index++;
        cin>>arr;
        if(arr[0]=='-'){
            break;
        }
        int length = 0;
        dem = 0;
        while(arr[length] == '}' || arr[length] == '{') length++;
        p++;
        arrStack[p] = arr[0];
        for(int i = 1; i < length; i++){
          if(arrStack[p] == '{' && arr[i] == '}'){
            p--;
          }else{
            p++;
            arrStack[p] = arr[i];
          }
        }
        for(int i = 1; i < p; i+=2){
            if(arrStack[i]=='}' && arrStack[i+1]=='{'){
                dem += 2;
            }else if((arrStack[i]=='}'&& arrStack[i+1]=='}')||(arrStack[i]=='{' && arrStack[i+1]=='{')){
                dem++;
            }
        }
        cout<<index<<". "<<dem<<endl;
        for(int i = 0; i <= length; i++){
            arr[i] = ' ';
        }
        p=0;
    }
    return 0;
}
