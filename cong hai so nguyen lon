#include<iostream>
using namespace std;

string add(string a, string b)
{
	string num = "";
	int mem = 0;
	
	while(a.size() < b.size())
		a = "0" + a;
	while(a.size() > b.size())
		b = "0" + b;
		/*1234
		  8927
		  _____
	    "10161" */
	
	int len = a.size() - 1;
	//thuc hien cong hai so tu phai qua trai
	for(int i = len; i >= 0; i--)
	{
		int so = int (a[i]-'0') + int (b[i]-'0') + mem;
		num = char(so%10+'0') + num;
		mem = so/10;
	}
	if(mem > 0)
		num = char(mem+'0') + num;
	return num;
}

int main()
{
	string a, b;
	cin >> a >> b;
	cout << add(a,b) << endl;
	return 0;
}
