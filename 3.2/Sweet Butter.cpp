/*
ID:15256292
LANG:C++
TASK:butter
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define INF 100000000
typedef struct Node {
	int node;
	int l;
	friend bool operator < (Node a,Node b){
		return a.l>b.l;
	}
};
Node path[801][801];
int spath[801];
bool mark[801];
int Num[801];
int N,P,C;
int minnum=INF;
priority_queue <Node> q;
int cownum[801];
void init(){
	for(int i =1;i<=800;i++)
		Num[i]=1;
	int at,v1,v2,p;
	cin>>N>>P>>C;
	for(int i=1;i<=N;i++){
		cin>>at;
		cownum[at]++;
	}
	for(int i=1;i<=C;i++){
		cin>>v1>>v2>>p;
		path[v1][Num[v1]].node=v2;
		path[v1][Num[v1]++].l=p;
		path[v2][Num[v2]].node=v1;
		path[v2][Num[v2]++].l=p;
	}
	
}
void print(){
		for(int j=1;j<=P;j++)
			cout<<spath[j]<<"\t";
		cout<<endl;
}
void sumPath(){
	int sum=0;
	for(int j=1;j<=P;j++)
		sum+=cownum[j]*spath[j];
	if(minnum>sum)
		minnum=sum;
}
int main(){
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	init();
	Node st;
//	print();
	int begin;
	int min1=INF;
	for(int k=1;k<=P;k++){
		for(int i=1;i<=800;i++){
			mark[i]=0;
			spath[i]=INF;
		}
		mark[k]=true;
		spath[k]=0;
		begin=k;
		for(int i=1;i<=P;i++){
			for(int j=1;j<Num[begin];j++){
				if(spath[path[begin][j].node]>spath[begin]+path[begin][j].l){
						spath[path[begin][j].node]=spath[begin]+path[begin][j].l;
						st.l=spath[path[begin][j].node];
						st.node=path[begin][j].node;
						q.push(st);	
					}
				}
				if(!q.empty()){
					begin=q.top().node;
					q.pop();
				}
				while(!q.empty()&&mark[begin]){
					begin=q.top().node;
					q.pop();
				}
				mark[begin]=true;
		}
//		print();
		sumPath();
	}			
	cout<<minnum<<endl;
}
