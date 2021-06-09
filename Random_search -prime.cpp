#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;

#define N 50
int d;

int *chuyenNhiPhan(int k)
{
	static int bin[N];
	int i = 0;
	while(k>0)
	{
		if(k%2 == 0) bin[i] = 0;
		else bin[i] = 1;
		k/=2;
		i++;
	}
	d = i-1;
	return bin;
}

int binhPhuongCoLap(int a, int k, int n) //a^k modn = b
{
	int *bin = chuyenNhiPhan(k);
	int b = 1;
	int A = a;
	if(k == 0) return b;
	if(bin[0] == 1)  b = a;
	for(int i = 1; i <= d; i++)
	{
		A = (A*A)%n;
		if(bin[i] == 1) b = (b*A)%n;
	}
	return b;
}

bool Miller_Rabin(int n, int t)
{
	int s, r;
	s = 0;
	int mark = n-1;
	// chuyen n-1 = 2^s*r
	while(mark%2 == 0)
	{
		s++;
		mark/=2;
	}
	r = mark;
	//thuc hien thuat toan
	while(t > 0)
	{
		int a, y;
		
		a = 2 +rand()%(n-2);
		y = binhPhuongCoLap(a, r, n);
		
		if(y != 1 && y != (n-1))
		{
			int j = 1;
			while(j <= (s-1) && y != (n-1))
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

bool Ktra_Ngto(int n)
{
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n%i == 0 && n != i) return false;
	}
	return true;
}

int Random_search(int k, int t)
{
	int n, count = 0;	
	int mark1, mark2;
	mark1 = mark2 = 0;
	
	do{
		do
		{	
			int max = 0;
			for(int i = 0; i < k; i++)
			{
				max+=pow(2, i);
			}
			// b1: sinh ngau nhien mot so nguyen n co k-bit
			srand(time(NULL));
			n = 2 +rand()% max;
			// xac dinh lieu n co chia het cho mot so nguyen to bat ki <= n/2 khong
			int test;
			test = 2 + rand()%(n-1);
			while(Ktra_Ngto(test) == false)
				test = 2 + rand()%(n/2);
			if(n%test == 0) mark1 = 0; // neu n chia het thi quay lai b1
			else mark1 = 1;
			
		}while(mark1 == 0);
		if(Miller_Rabin(n, t) == true) return n;
		else mark2 = 0; // quay lai b1
	}while(mark2 == 0);
	
} 

int main()
{
//	cout << binhPhuongCoLap(12, 57, 85);
	int k, t;
	cout << "nhap bit: "; cin >> k;
	cout << "nhap so lan kiem tra (Miller Rabin): "; cin >> t;
	cout << Random_search(k, t);
	return 0;
}






