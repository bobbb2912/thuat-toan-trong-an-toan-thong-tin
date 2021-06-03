#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int squareAndMulti(int a, int k, int n) //a^k mod n = r
{
	int b = 1;
	int A = a;
	while(k>0)
	{
		A = (A*A)%n;
		if(k%2 == 1) b = (b*A)%n;
	
		k/=2;
	}
	return b;	 
}

bool Fermat(int n, int t)
{
	if(n == 1) return false;
	for(int i = 0; i < t; i++)
	{
		int a, r;
	//	srand (time(NULL));
		a = 2 + rand()%(n-2); //tao ngau nhien a trong khoang 2->(n-2)
		r = squareAndMulti(a, n-1, n);
		if(r != 1) return false;		
	
	}
	return true;
}

int main()
{
	int n, t;
	cin >> n >> t;
	if(Fermat(n, t) == 0) cout << "hop so";
	else cout << "nguyen to";
	return 0;
}
