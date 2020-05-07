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
int main()
{
    int n,t;
    cin >> t;
    while(t > 0){
        cin >> n;
        if(isPrimeNumber(n) == 1 && isPrimeNumber(n +4) == 1) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
        t--;
    }
    return 0;
}
