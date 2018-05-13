/*
ID: 15256292
LANG: C++ 
TASK: subset
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<math.h>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");
int main()
{
	int n,m,nt;
	long long dp[400];
	for(int i=0;i<400;i++)
		dp[i]=0;
	dp[0]=1;
	fin>>n;
	m=(1+n)*n/2;
	if(m%2!=0)
	{
		fout<<0<<endl;
		return 0 ;
	}
	m=m/2;
	for(int i=1;i<=n;i++)
	{
		nt=i;	
		for(int j=m;j>=nt;j--)
			dp[j]+=dp[j-nt];
	}
	fout<<dp[m]/2<<endl;
}
