/*
ID: 15256292
LANG: C++ 
TASK: combo
*/
#include <iostream>
#include <fstream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
ifstream fin("combo.in");
ofstream fout("combo.out");
int N;
struct Key
{
	int begin;
};
int num[101][101][101];
int sum=0;
Key k[10];
int main()
{
	fin>>N;
	if(N<=5)
	{
		fout<<N*N*N<<endl;
		return 0;
	}
	int n;
	for(int i=0;i<6;i++)
	{
		fin>>n;
		k[i].begin=(n-2+N)%N;
		
	}
	for(int i1=k[0].begin;i1<k[0].begin+5;i1++)
		for(int i2=k[1].begin;i2<k[1].begin+5;i2++)
			for(int i3=k[2].begin;i3<k[2].begin+5;i3++)
				num[i1%N][i2%N][i3%N]=2;
	for(int i1=k[3].begin;i1<k[3].begin+5;i1++)
		for(int i2=k[4].begin;i2<k[4].begin+5;i2++)
			for(int i3=k[5].begin;i3<k[5].begin+5;i3++)
				num[i1%N][i2%N][i3%N]=2;
	for(int i1=0;i1<=N;i1++)
		for(int i2=0;i2<=N;i2++)
			for(int i3=0;i3<=N;i3++)
				if(num[i1][i2][i3]==2)
					sum++;
	fout<<sum<<endl;
	return 0;
}
