#include <iostream>

using namespace std;

char arr[5002];
int ans[5002];
int leng = 0;
void getLength(){
    leng = 0;
    while(1){
        if(arr[leng] != '\0'){
            leng++;
        }else{
            break;
        }
    }
}
int main()
{
    while(1){
        cin >> arr;
        if(arr[0] == '0'){
            break;
        }
        getLength();
        for(int i = 0; i < leng; i++){
            ans[i] = 0;
        }
        int i = 1;
        ans[0] = 1;
        int tmp;
        while(i < leng){
            tmp = 0;
            tmp = (arr[i - 1] - '0') * 10;
            tmp += arr[i] - '0';
            if(arr[i] != '0'){
                ans[i] = ans[i - 1];
            }
            if(tmp <= 26 && tmp > 9){
                ans[i] += ans[i - 2 < 0 ? 0 : i - 2];
            }
            i++;
        }
        cout << ans[leng - 1] << endl;
    }
    return 0;
}
