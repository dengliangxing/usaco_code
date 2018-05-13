/*
ID:15256292
LANG:C++
TASK:agrinet
*/ 
#include<iostream>
#include<fstream>
using namespace std;
#define INF 1000000
bool mark[101];
int map[101][101];
int min1=INF;
int sum=0;
int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	int N;
	int v1,v2;
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>map[i][j];
	mark[1]=true;
	for(int v=1;v<N;v++){
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
			if(mark[i]!=mark[j]&&min1>map[i][j]){
				v1=i;
				v2=j;
				min1=map[i][j];
			}
		mark[v1]=true;
		mark[v2]=true;
		sum+=min1;
		min1=INF;
	}
	cout<<sum<<endl;
}
