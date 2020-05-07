#include<iostream>
using namespace std;

const int MAX = 200005;

long long Answer;
int N, T;
int a[MAX];

void Merge(int left, int m, int right)
{
	int temp[right - left + 1];
	int k = 0, i = left, j = m + 1;

	while(i <= m && j <= right)
	{
		if(a[i] > a[j])
		{
			temp[k++] = a[i++];
			Answer += right - j + 1;
		}
		else
		{
			temp[k++] = a[j++];
		}
	}

	while(i <= m) temp[k++] = a[i++];
	while(j <= right) temp[k++] = a[j++];

	for(int i = 0; i < k; i++)
		a[i + left] = temp[i];
}

void MergeSort(int left, int right)
{
	int m;
	if(left < right)
	{
		m = (left + right) / 2;
		MergeSort(left, m);
		MergeSort(m + 1, right);
		Merge(left, m, right);
	}
}

int main()
{
	cin >> T;
	for(int tc = 0; tc < T; tc++)
	{
		Answer = 0;
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> a[i];

		MergeSort(0, N-1);
		cout << Answer << endl;
	}
	return 0;
}
