/*
ID: 15256292
LANG: C++ 
TASK: numtri
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("numtri.in");
ofstream fout("numtri.out");
int num[1080][1080];
int max1(int a,int b)
{
	if(a>b)
		return a;
	else
		return b; 
	
} 
int main()
{
	int n;
	fin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		fin>>num[i][j];
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=n-1;j++)
			num[i][j]+=max1(num[i+1][j],num[i+1][j+1]);
	fout<<num[1][1]<<endl;
	
}
