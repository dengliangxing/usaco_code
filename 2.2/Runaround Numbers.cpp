/*
ID: 15256292
LANG: C++ 
TASK: runround
*/
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");
bool isdif(int n)
{
	bool is[20];
	memset(is,0,sizeof(is));
	while(n!=0)
	{
		int t= n%10;
		if(is[t]||t==0)
			return false;
		is[t]=true;
		n/=10;
	}
	return true;
}
bool isround(int n)
{
	char c[20];
	bool is[10];
	memset(is,0,sizeof(is));
	sprintf(c,"%d",n);
	int sum=0;
	while(c[sum++]!='\0');
	sum--;
	int begin=c[0]-'0';
	int s=0;
	is[0]=true;
	while(true)
	{
		begin=(begin+s)%sum;
		if(is[begin])
			break;
		else
			is[begin]=true;
		s=begin;
		begin=c[begin]-'0';
	 } 
	 if(begin!=0)
	 	return false;
	for(int i=0;i<sum;i++)
		if(!is[i])
			return false;
	return true;
}
int main()
{
	int N;
	fin>>N;
	N++;
	while(true)
	{
		if(isdif(N)&&isround(N))
			break;
		N++;
	}
	fout<<N<<endl;
}
