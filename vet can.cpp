#include<iostream>
#include<string>
using namespace std;

int Vet_Can (string T, string P)
{
	int n = T.size(); // do dai chuoi T
	int m = P.size(); // do dai chuoi P
//	cout << n << "\t"<<m<<endl<<endl;

	int i, j; // i la chi so cua T, j la chi so cua P
	i = j = 0; 
	int mark = 0; // bien danh dau
	int count = 0;	// bien dem so lan P xuat hien trong T
	while(i < n)
	{
		if(T[i] == P[j] && i <n && j < m)
		{	
			mark++;
			i++;
			j++;
		}
		else i++;
		if(mark == m)
		{
			cout << "Tim thay chuoi tai vi tri " << i-m << endl;
			j = 0;
			mark = 0;
			count++;
			i++;
		} 
		
	}
	if(count == 0) cout << "Khong tim thay chuoi";	
	else cout << "Tim thay " << count << " ket qua!";
}

int main()
{
	string T, P;

	cout << "Nhap chuoi: "; cin.ignore(T.size(),'\n'); // xoa bo nho dem
	getline(cin, T);
	cout << "Nhap chuoi can tim kiem: "; cin.ignore(P.size(),'\n'); 
	getline(cin, P);
	
	Vet_Can(T, P);
	return 0;
}

