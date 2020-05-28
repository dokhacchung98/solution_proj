#include <iostream>

using namespace std;
int n, t, m;
int arr[505];
int tmps[505];
int tmpe[505];
void update(int x, long mid){
    long s = 0;
    int k = tmps[x];
    for(long i = tmps[x+1] - 1; i >= k; i--){
        s += arr[i];
        if(s == mid){
            tmps[x] = i;
            break;
        }else if(s > mid){
            tmps[x] = i + 1;
            break;
        }
    }
}
int isValid(long mid){
    for(int i = 0; i < m; i++){
        tmps[i] = i;
    }
    tmps[m] = n;
    for(int i = m - 1; i >= 0; i--){
        update(i, mid);
    }
    if(tmps[0] > 0){
        return 0;
    }
    return 1;
}
int main()
{
    cin >> t;
    while(t > 0){
        cin >> n >> m;
        long maxPage = 0;
        long sumPage = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] > maxPage){
                maxPage = arr[i];
            }
            sumPage += arr[i];
        }
        long l = maxPage;
        long r = sumPage;
        while(l < r){
            long mid = (l + r)/2;
            if(isValid(mid) == 1){
                r = mid;
                for(int i = 0; i < m; i++){
                    tmpe[i] = tmps[i];
                }
            }else{
                l = mid + 1;
            }
        }
        for(int i = 0; i < m - 1; i++){
            for(int j = tmpe[i]; j < tmpe[i+1]; j++){
                cout << arr[j] << " ";
            }
            cout << "/ ";
        }
        for(int i = tmpe[m-1]; i < n;  i++){
            cout << arr[i];
            if(i == n - 1){
                break;
            }
            cout << " ";
        }
        cout << endl;
        t--;
    }
    return 0;
}
