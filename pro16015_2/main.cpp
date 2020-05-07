#include <iostream>

using namespace std;
int arrHeight[1000];
int arrpos[1000];
int arrResult[1000];
void swapPosition(int p1, int p2){
    int tmp = arrHeight[p1];
    arrHeight[p1] = arrHeight[p2];
    arrHeight[p2] = tmp;
    tmp = arrpos[p1];
    arrpos[p1] = arrpos[p2];
    arrpos[p2] = tmp;
}

int main()
{
    int t = 0, n = 0, dem = 0;
    cin >> t;
    while(t > 0) {
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arrHeight[i];
        }
        for(int i = 0; i < n; i++){
            cin >> arrpos[i];
            arrResult[i] = -1;
        }
        int tg;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(arrHeight[i] > arrHeight[j]){
                    swapPosition(i, j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            dem = 0;
            for(int j = 0; j < n; j++){
                if(arrResult[j] == -1 && dem == arrpos[i]){
                    arrResult[j] = arrHeight[i];
                    break;
                }
                if(arrResult[j] == -1){
                    dem++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << arrResult[i] << " ";
        }
        cout<<endl;
        t--;
    }
    return 0;
}
