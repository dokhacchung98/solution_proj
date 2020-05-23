#include <iostream>

using namespace std;
int t;
int ts[100000];
int te[100000];
int n;
int ans = 0;
void sw(int a, int b){
    int tmp = ts[a];
    ts[a] = ts[b];
    ts[b] = tmp;
    tmp = te[a];
    te[a] = te[b];
    te[b] = tmp;
}
void quickSort( int l , int r)
{
	if (l <= r)
	{
		int key = te[(l+r)/2];
 		int i = l;
		int j = r;
		while (i <= j)
		{
			while (te[i] < key)
				i++;
			while (te[j] > key)
				j--;
			if (i <= j)
			{
				sw(i, j);
				i++;
				j--;
			}
		}
		if (l < j)
			quickSort(l, j);
		if (r > i)
			quickSort(i, r);
	}
}
void tryGet(){
    ans = 1;
    int e = te[0];
    for(int i = 1; i < n; i++){
        if(te[i] != e && ts[i] >= e){
            ans++;
            e = te[i];
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
            scanf("%d",&ts[i]);
            scanf("%d",&te[i]);
        }
        quickSort(0, n-1);
        tryGet();
        printf("%d\n",ans);
        t--;
    }
    return 0;
}
