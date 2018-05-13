/*
ID: 15256292
LANG: C++ 
TASK: wormhole
*/
#include<iostream>
#include<map>
#include<fstream>
#include<algorithm>
using namespace std;
ofstream fout("wormhole.out");
ifstream fin("wormhole.in");
struct Node
{
	long x;
	long y;
};
Node node[20];
int sum=0;
int NUM[20];
int end=1;
bool num[15];
int n;
long next[15];
long g[15]; 
bool cmp(Node a,Node b)
{
	if(a.y==b.y)
		return a.x<b.x;
	else
		return a.y<b.y;
}
void init1()
{
	for(int i=1;i<=14;i++)
		g[i]=0;
}
void init()
{
	for(int i=0;i<14;i++)
		num[i]=true;
	fin>>n;
	for(int i=0;i<n;i++)
		fin>>node[i].x>>node[i].y;
	sort(node,node+n,cmp);
	for(int i=0;i<n-1;i++)
		if(node[i].y==node[i+1].y)
			next[i+1]=i+2;
	init1();
}
void check()
{
	int i,j;
	for(i=1;i<end;i=i+2)
	{
		g[NUM[i]]=NUM[i+1];
		g[NUM[i+1]]=NUM[i];
	}
	for(int i=1;i<=n;i++)
	{
		int begin=i;
		for(j=1;j<=15;j++)
		{
			begin=next[begin];
			if(begin==0)
				break;
			begin=g[begin];
		}
		if(j==16)
			{
				sum++;
				break;
			}
	}
 init1();
}
void DFS(int N)
{
	if(N==n)
	{
		check();
		return ;
	}
	int i;
	for(i=N+1;i<=n;i++)
		if(num[N])
			{
				if(num[i])
				{
					NUM[end++]=N;
					NUM[end++]=i;
					num[N]=false;
					num[i]=false;
					DFS(N+1);
					num[N]=true;
					num[i]=true;
					end=end-2;
				}
			}
		else
		{
			DFS(N+1);
			break;
		}	
}
int main()
{	
	init();
	DFS(1);
	fout<<sum<<endl;
}
