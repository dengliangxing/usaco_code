/*
ID: 15256292
LANG: C++ 
TASK: barn1
*/
#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("barn1.in");
ofstream fout("barn1.out");

int num[300];
int l[300];
int M,S,C;
bool cmp(int a,int b)
{
	return a>b;
}
bool cmp1(int a,int b)
{
	return a<b;
}
void init()
{
	fin>>M>>S>>C;
	for(int i=0;i<C;i++)
		fin>>num[i];
	sort(num,num+C,cmp1);
	for(int i=0;i<C-1;i++)
	l[i]=num[i+1]-num[i]-1;
	sort(l,l+C-1,cmp);
}

int main()
{
	int sum=0;
	init();
	for(int i=0;i<M-1;i++)
	sum+=l[i];
	fout<<num[C-1]-num[0]-sum+1<<endl;
}
