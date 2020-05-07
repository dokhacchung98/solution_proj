#include <iostream>
#include <math.h>
using namespace std;
int isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s*s == x) ? 1 : 0;
}
int isFibonacci(int n)
{
    return (isPerfectSquare(5*n*n + 4) == 1 ||
           isPerfectSquare(5*n*n - 4) == 1) ? 1 : 0;
}
int main()
{
    int t, n;
    cin >> t;
    while(t > 0){
        cin >> n;
        if(isFibonacci(n) == 1) {
            cout << "YES" << endl;
        }else {
            cout << "NO" <<endl;
        }
        t--;
    }
    return 0;
}
