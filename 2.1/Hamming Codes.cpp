/*
ID: 15256292
LANG: C++ 
TASK: hamming
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("hamming.in");
ofstream fout("hamming.out");
int num[77];
int sum=1;
int N,B,D;
bool isHamming(int begin)
{
	
	for(int i=0;i<sum;i++)
	{
		int sumh=0;
		for(int j=0;j<B;j++)
		if((begin&(1<<j))!=(num[i]&(1<<j)))
			sumh++;
			
		if(sumh<D)
			return false;
	}
	return true;
}
void DFS(int begin)
{
	if(sum>=N)
		return;
	if(isHamming(begin))
		num[sum++]=begin;
	DFS(begin+1);
}
int main()
{
	fin>>N>>B>>D;
	DFS(1>>B-1);
	for(int i=0;i<N-1;i++)
		if(i%10!=9)
		fout<<num[i]<<" ";
		else
		fout<<num[i]<<endl;
		fout<<num[N-1]<<endl;
}
