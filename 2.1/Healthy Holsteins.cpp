/*
ID: 15256292
LANG: C++ 
TASK: holstein
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
int need[60];
int needo[60];
int minneed[60];
int offer[30][60];
int v,g;
int min1=100;
void DFS(int n,int sum)
{
	
	int i;
	for(i=1;i<=v;i++)
		if(need[i]>0)
			break;
	if(i==v+1)
	{
		for(i =0;i<sum;i++)
			minneed[i]=needo[i];
		min1=sum;
	}
	if(sum>=min1-1)
		return;
	if(n==g+1)
		return ;
	for(int i=1;i<=v;i++)
		need[i]-=offer[n][i];
	needo[sum++]=n;
	DFS(n+1,sum);
	sum--;
	for(int i=1;i<=v;i++)
		need[i]+=offer[n][i];
	DFS(n+1,sum);
}
int main()
{
	fin>>v;
	for(int i=1;i<=v;i++)
		fin>>need[i];
	fin>>g;
	for(int i=1;i<=g;i++)
		for(int j=1;j<=v;j++)
			fin>>offer[i][j];
	DFS(1,0);
	fout<<min1<<" ";
	for(int i=0;i<min1-1;i++)
		fout<<minneed[i]<<" ";
	fout<<minneed[min1-1]<<endl;
}
