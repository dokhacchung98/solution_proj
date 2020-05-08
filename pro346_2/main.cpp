#include <iostream>
using namespace std;

unsigned long int coins(unsigned long int n)
{
     unsigned long int a=n/2, b=n/3, c=n/4;
     if (a+b+c>n)
		 return coins(a)+coins(b)+coins(c);
     return n;
}

int main() {
     unsigned long int n;

	 while(cin >> n)
     {
          cout << coins(n) << endl;
     }
	 return 0;
}
