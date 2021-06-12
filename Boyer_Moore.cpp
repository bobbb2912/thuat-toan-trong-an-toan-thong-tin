#include<iostream>
#include<string>
using namespace std;

#define MAX_CHAR 256

void badCharHeuristic(string str, int size, int badchar[MAX_CHAR])
{
	int i;
	for(i = 0; i < MAX_CHAR; i++)
	{
		badchar[i] = -1; //dat tat ca cac khoang ky tu la -1
//		cout << "badchar["<<i<<"] = "<< badchar[i]<<endl;
		
	}
		
	for(i = 0; i < size; i++)
	{
		badchar[(int) str[i]] = i; // dat vi tri cua cac ky tu trong mang
//		cout << "badchar["<<str<<"["<<i<<"]"<<"] = "<<	badchar[(int) str[i]]<<endl;

		
	}
}

void Boyer_Moore(string T, string P)
{
	int n = T.size(); // kich thuoc text
	int m = P.size(); // kich thuoc pattern
//	cout << n << "\t"<<m<<endl<<endl;
	int badchar[MAX_CHAR];

	
	badCharHeuristic(P, m, badchar);
//		for(int i = 0; i < n; i++)
//	{
//		cout << badchar[T[i]] <<endl;
//	}
	int s = 0;
	int count = 0;
	while(s <= (n-m))
	{
		int j = m-1; 
		while(j >= 0 && P[j] == T[s+j]) 
			j--;
		if(j < 0) // khi nay tai vi tri s -> P khop T
		{
			cout << "mau P trong T bat dau tu vi tri: " << s << endl;
			s +=(s+m < n) ? m - badchar[T[s+m]] : 1;
//			cout << badchar[T[s+m]]<<endl;
			count++;
		}
		else // khi nay P khong khop T
		{
//			cout<<s<<"\t"<<j<<"\t" << max(1, j - badchar[T[s+j]])<< "\t"<< badchar[T[s+j]]<< endl;
			s += max(1, j - badchar[T[s+j]]);
			
		
		}
	}
	if(count == 0) cout << "khong co chuoi can tim!";
} 

int main()
{
	string T, P;

	cout << "Nhap chuoi: "; cin.ignore(T.size(),'\n'); // xoa bo nho dem
	getline(cin, T);
	cout << "Nhap chuoi can tim kiem: "; cin.ignore(P.size(),'\n'); 
	getline(cin, P);
	
	Boyer_Moore(T, P);
	return 0;
}


