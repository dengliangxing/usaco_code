/*
ID:15256292
LANG:C++
TASK:sort3
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("sort3.in");
ofstream fout("sort3.out");
int num[4];
int num1[4][4];
int seq[5000];
int n;
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
		{
			fin>>seq[i];
			num[seq[i]]++;
		}
	int sum1=0;
	int sum2=0;
	for(int i=0;i<3;i++)
	{
		
		for(int j=sum1+1;j<=sum1+num[i+1];j++)
		{
			num1[i+1][seq[j]]++;
			if(seq[j]==i+1)
				sum2++;
		}
			sum1+=num[i+1];
	}
	int sum=0;
	for(int i=1;i<=3;i++)
		for(int j=i+1;j<=3;j++)
				sum=sum+min(num1[i][j],num1[j][i]);
	fout<<sum+(n-sum2-2*sum)/3*2<<endl;
}
