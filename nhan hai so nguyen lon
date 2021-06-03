#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string mul(string s1, string s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	int len = len1 + len2;

	vector<int> a, b;
	//day cac phan tu cua s1 vao vector a va chuyen sang kieu so nguyen
	for(int i = 0; i<len1; i++)
		a.push_back(int(s1[i] -'0'));
	//day cac phan tu cua s2 vao vector b va chuyen sang kieu so nguyen
	for(int i = 0; i<len2; i++)
		b.push_back(int(s2[i]-'0'));

	
	vector < vector<int> > res(len2); //khoi tao mot vector chua tat ca cac vector va co kich thuoc len2 hang
	 
	 int index = 0;
	 for(int i = len2-1; i>=0; i--)
	 {
	 
	 	int t = 0;
	 	while(t<index)
	 	{
	 		res[index].push_back(0); //push '0' vao res[index] 
			 /* 1234
			     123
			___________
			  00xxxx
			  0xxxx0
			  xxxx00
			  _______*/
	 		
	 		t++;
		}
		int mem = 0, so = 0;
		
		//thuc hien nhan vector b voi lan luot cac phan tu trong vector a => res[index]
		for(int j = len1-1; j>=0; j--)
		{
			so = a[j] *b[i] + mem;
			res[index].push_back(so%10); //push back cac ket qua nhan duoc vao res[index]
			mem = so/10;
		}
		
		if(mem > 0) res[index].push_back(mem);
		while(res[index].size() < len) 
			res[index].push_back(0); //push '0' de res.size = len
		reverse(res[index].begin(), res[index].end()); // dao nguoc res
		index++;
	 }
	 int mem = 0;
	 string ans = "";
	 //thuc hien cong tung cot voi nhau trong res (i hang j cot) => answer
	 for(int j = res[0].size()-1; j>=0; j--)
	 {
	 	int so = mem; 
	 	for(int i = 0; i<res.size();i++)
	 		so+=res[i][j];
	 	ans = char(so%10 + '0') + ans;
	 	mem = so/10;
	 }
	 if(mem > 0) ans = char(mem + '0') + ans;
	 while(ans[0] == '0') ans.erase(ans.begin());
	 return ans;
}

int main()
{
	string a, b;
	
	cin >> a >> b;
	cout << mul(a,b);
	
	return 0; 
}
