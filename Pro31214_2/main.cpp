#include <iostream>
#include <math.h>
using namespace std;
int isPrimeNumber(int k){
    if (k == 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0) {
            return 0;
        }
    }
    return 1;
}
int getPrimeNumber(int n){
    for (int i = n; i >= 2; i--) {
        if (isPrimeNumber(i) == 1) {
            return i;
        }
    }
    return 0;
}
int main()
{
    int t, n;
    cin >> t;
    while(t > 0) {
        cin >> n;
        cout << getPrimeNumber(n) << endl;
        t--;
    }
    return 0;
}
