#include <iostream>
#include <math.h>

using namespace std;

int getCubeNumber(int n){
    int tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (i * i * i <= n) {
                tmp = i;
            } else {
                return tmp;
            }
        }
        return tmp;
}

int main()
{
    int t = 0;
    cin >> t;
    while(t > 0){
        int n = 0;
        cin >> n;
        int result = getCubeNumber(n);
        cout << result << endl;
        t--;
    }
    return 0;
}
