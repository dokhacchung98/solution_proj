#include <iostream>
#include <math.h>
using namespace std;
int getFactorial(int n){
    if(n == 1){
        return 1;
    }
    return n * getFactorial(n - 1);
}
int isPrimeNumber(int k){
    if (k <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0) {
            return 0;
        }
    }
    return 1;
}
int isFactorialPrimeNumber(int k){
    if(isPrimeNumber(k) == 0){
        return 0;
    }
    for(int i = 1; i<=k; i++){
        int tmp = getFactorial(i);
        if(tmp <= k+1){
            if(k == tmp || k == tmp - 1 || k == tmp + 1){
                return 1;
            }
        }else{
            return 0;
        }
    }
}
int main()
{
    int t, n;
    cin >> t;
    while(t > 0){
        cin >> n;
        if(isFactorialPrimeNumber(n) == 1) {
            cout << "YES" << endl;
        }else {
            cout << "NO" <<endl;
        }
        t--;
    }
    return 0;
}
