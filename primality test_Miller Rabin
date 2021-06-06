#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;


int squareMulti(int a, int k, int n) // a^k mod n = b
{
	int b = 1;
	int A = a;
	while(k > 0)
	{
		A = (A*A)%n;
		if(k%2 == 1) b = (b*A)%n;
		
		k/=2;
	}
	return b;
}

bool Miller_Rabin(int n, int t) 
{
	int a, r, y, s;
	int mark = n-1;
	s = 0;
	// phan tich n-1 = 2^s.r
	while(mark%2 == 0)
	{
		s++;
		mark/=2;
	}
	r = mark;
	
	while(t > 0)
	{
	
		a = 2 + rand()%(n-2);
		y = squareMulti(a, r, n);
		if(y!=1 && y!=(n-1))
		{
			int j = 1;
			while(j < (s-1) && y != (n-1))
			{
				y = (y*y)%n;
				if(y == 1) return false;
				j++;
			}
			if(y != (n-1)) return false;
		}
		t--;
	}
	return true;
}

int main()
{
	int n, t;

	cin >> n >> t;
	if(n<2) cout << "nhap n > 2.";
	else
	{
		if(n == 2) cout << "nguyen to";
		else
		{
			if(Miller_Rabin(n, t) == 1) cout << "nguyen to";
			else cout << "hop so";
		}
	}

	return 0;
}
