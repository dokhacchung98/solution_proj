#include <iostream>
#include <algorithm>

using namespace std;
long int n;
int t;
int c;
long long int arr[100000];
int result = 0;
int main()
{
    cin >> t;
    while(t > 0){
        cin >> n >> c;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        while(1){

            result++;
        }
        t--;
    }
    return 0;
}
