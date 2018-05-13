/*
ID:15256292
LANG:C++
TASK:fence6
*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
#define INF 10000000
int g[102][102],N,size[102],sign[105],MIN=INF,begin,sum;
bool mark[102],tt[102];
void init(){
	int v1,v2,v,t;
	for(int i=1;i<=100;i++)
		sign[i]=3;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>v;
		cin>>size[v]>>v1>>v2;
		for(int j=1;j<=v1;j++){
			cin>>t;
			g[v][t]=1;
		}
		for(int j=1;j<=v2;j++){
			cin>>t;
			g[v][t]=2;
		} 
		
	}
}  
void DFS(int v){
	for(int i=1;i<=N;i++)
		if(g[v][i]>0&&mark[i]==0&&tt[i]==0){
			if(sign[v]==3||sign[v]==g[v][i]){
				mark[i]=1;
				sum+=size[i];
				sign[v]-=g[v][i];
				sign[i]-=g[i][v];
				DFS(i);
				sign[v]+=g[v][i];
				sign[i]+=g[i][v];
				sum-=size[i];
				mark[i]=0;
			}
		}else if(g[i][v]==sign[begin]&&i==begin)
			MIN=MIN>sum?sum:MIN;
					
}
void print(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<g[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	init();
//	print();
	for(int i=1;i<=N;i++){
		begin=i;
		mark[i]=1;
		sum+=size[i];
		DFS(i);
		sum-=size[i];
		mark[i]=0;
		tt[i]=1;
	}
	cout<<MIN<<endl;
}
