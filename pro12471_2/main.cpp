#include <iostream>

using namespace std;
int t;
int h, a;
int tmp[1000][1000];
int getMax(int a, int b){
    return a > b ? a : b;
}
/*
    Tốt nhất là người chơi đứng từ air, sau đó thực hiện 2 bước nhảy air -> water -> air (1) hoặc air -> fire -> air (2)
    (1) h = h - 5 + 3 = h - 2; a = a - 10 + 2 = a - 8;
    (2) h = h - 20 + 3 = h - 17; a = a + 5 + 2 = a + 7;
    nếu thực hiện 2 bước nhảy mà còn sống -> +2 lượt sống
    nhảy 2 bước mà die -> -1
    mảng tmp[h][a] lưu trữ giá trị số lần sống cao nhất tại số h và a
*/
int tryJump(int h, int a){
    if(h <= 0 || a <= 0){
        return -1;
    }
    if(tmp[h][a] == -1){
        tmp[h][a] = getMax(2 + tryJump(h - 2, a - 8), 2 + tryJump(h - 17, a + 7));
    }
    return tmp[h][a];
}
int main()
{
    cin >> t;
    while(t > 0){
        cin >> h;
        cin >> a;
        for(int i = 0; i <= getMax(h, a); i++){
            for(int j = 0; j <= getMax(h, a); j++){
                tmp[i][j] = -1;
            }
        }
        cout << tryJump(h, a) << endl;
        t--;
    }
    return 0;
}
