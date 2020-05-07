#include <iostream>
//https://math.stackexchange.com/questions/517555/fastest-way-to-check-if-xy-yx
using namespace std;
int arr[100000];
void quickSort( int l , int r)
{
	if (l <= r)
	{
		int key = arr[(l+r)/2];
 		int i = l;
		int j = r;
		while (i <= j)
		{
			while (arr[i] < key)
				i++;
			while (arr[j] > key)
				j--;
			if (i <= j)
			{
				swap(arr[i], arr[j]);
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
int main()
{
    int t, n, tmp;
    cin >> t;
    int index, indexOfOne;
    while(t > 0){
        cin >> n;
        index = -1;
        indexOfOne=0;

        for(int i = 0; i < n; i++){
            cin >> tmp;
            if(tmp == 1){
                indexOfOne++;
            }else {
                arr[++index] = tmp;
            }
        }
        for(int i = 0; i < indexOfOne; i++){
            cout<<"1 ";
        }
        if(index >= 0){
            if(index == 1 && ((arr[0] == 2 && arr[1] == 3) || (arr[0] == 3 && arr[1] == 2))){
                cout<<"2 3"<<endl;
            }else {
                quickSort(0, index);
                for(int i = index; i >= 0; i--){
                    cout<<arr[i]<<" ";
                }
            }
        }
        cout<<endl;
        t--;
    }
    return 0;
}
