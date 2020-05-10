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
    if((ts[x] < ts[y] && te[x] > ts[y])||
       (ts[x] > ts[y] && ts[x] < te[y])){
            return 1;
       }
    return 0;
}
void tryget(int x){
    if(v > ans){
        ans = v;
    }
    for(int i = x; i < n; i++){
        if(tmp[i] == 0){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(tmp[j] == 1 && check(j, i) == 1){
                    c = 1;
                }
            }
            if(c == 0){
                tmp[i] = 1;
                v++;
                tryget(i);
                v--;
                tmp[i] = 0;
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
        tryget(0);
        printf("%d\n",ans);
        t--;
    }
    return 0;
}
