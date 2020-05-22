#include <iostream>

using namespace std;
int t;
int ts[100000];
int te[100000];
int tmp[100000];
int n;
int ans = 0;
int v = 0;
int check(int x, int y){
    for(int i = x; i <= y; i++){
        if(tmp[i] == 1){
            return 0;
        }
    }
    return 1;
}
void tryget(x){
    if(x == n - 1 && ans )
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            tmp[j] = 0;
        }
        for(int j = i; j < n; j++){
            if(check(ts[j], te[j]) == 1){
                ans++;
                for(int k = ts[j]; k <= te[j]; k++){
                    tmp[k] = 1;
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t > 0){
        scanf("%d",&n);
        ans = 0;
        for(int i=0; i < n; i++){
            tmp[i] = 0;
            scanf("%d",&ts[i]);
            scanf("%d",&te[i]);
        }
        tryget();
        printf("%d\n",ans);
        t--;
    }
    return 0;
}
