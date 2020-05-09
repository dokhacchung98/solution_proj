#include <iostream>
using namespace std;
int indexSelected[10] = {0};
int arr[10] = {0};
int arrTmp[3] = {0};
int maxW = 0;
void C(int k, int n, int m){
    for(int i = 0; i < n; i++){
        if(indexSelected[i] == 0){
            arrTmp[k] = arr[i];
            indexSelected[i] = 1;
            if(k == 2){
                int w = arrTmp[0] + arrTmp[1] + arrTmp[2];
                if(w > maxW && w <= m){
                    maxW = w;
                }
            }else {
                C(k + 1, n, m);
            }
            indexSelected[i] = 0;
        }
    }
}
int getMaxWeight(int n, int m){
    if(n == 2){
        return arr[0] + arr[1] + arr[2];
    }
    maxW = 0;
    C(0, n, m);
    return maxW;
}
int main()
{
    int t = 0, n = 0, w = 0;
   
        cin >> t;

    while(t > 0){
        
            cin >> n;
        
        for(int i=0;i<n;i++){
            
                cin >> arr[i];
            
        }
        
            cin >> w;

        int result = getMaxWeight(n, w);
        cout << result << endl;
        t--;
        for(int i=0;i<n;i++){
            arr[i] =0 ;
        }
        n = 0;
        w = 0;
    }
    return 0;
}
