/*
ID: 15256292
LANG: C++ 
TASK: frac1
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("frac1.in");
ofstream fout("frac1.out");
struct Fra
{
	int a;
	int b;
	double num;
};
Fra num[100000];
int sum=0;
bool sign[161][161];
int check(int a,int b)
{
	while(a!=0&&b!=0)
	{
		b=b%a;
		int t=b;
		b=a;
		a=t;
	}
	return b+a;
}
bool cmp(Fra a,Fra b)
{
	return a.num<b.num;
}
int main()
{
	int n;
	fin>>n;
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int t=check(i,j);
			if(sign[i/t][j/t]==false)
			{
				sign[i/t][j/t]=true;
				num[sum].a=i;
				num[sum].b=j;
				num[sum++].num=i*1.0/j;
			}
			
		}
		num[sum].a=1;
		num[sum].b=1;
		num[sum++].num=1;
		sort(num,num+sum,cmp);
		for(int i=0;i<sum;i++)
			fout<<num[i].a<<"/"<<num[i].b<<endl;
}
