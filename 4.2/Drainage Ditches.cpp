/*
ID:15256292
LANG:C++
TASK:ditch
*/
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
#define INF 10000000
int sign[203][203],sum=0;
int amatrix[203][203];
int N,pathnum,begin,end;
int mark[203];
bool findpath(){
	int qu[203];
	memset(mark,-1,sizeof(mark));
	int start=0,rear=0,t;
	qu[rear++]=begin,mark[begin]=0;
	while(start!=rear){
		t=qu[start++];
		for(int i=1;i<=N;i++){
			if(amatrix[t][i]>0&&mark[i]==-1&&i!=end){
				mark[i]=t;
				qu[rear++]=i;
			}else if(amatrix[t][i]!=0&&i==end){
				mark[i]=t;
				return true;
			}
		}
	}
	return false;
}
void print(){
	cout<<endl<<endl;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<amatrix[i][j]<<"\t";
		cout<<endl;
	}
}
bool dealpath(){
	if(!findpath())
		return false;
	int t=end,MIN=INF;
	while(mark[t]!=0){
		MIN=MIN>amatrix[mark[t]][t]?amatrix[mark[t]][t]:MIN;
		t=mark[t];		
	}
	t=end;
	sum+=MIN;
	while(mark[t]!=0){
		amatrix[mark[t]][t]-=MIN;
		amatrix[t][mark[t]]+=MIN;
		t=mark[t];
	}
	return true;	
}
void DFS(int n){
	for(int i=1;i<=N;i++)
		if(mark[i]==-1&&amatrix[n][i]>0){
			mark[i]=1;
			DFS(i);
		}
}
int main(){
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
	int v1,v2,t;
	cin>>pathnum>>N;
	begin=1;
	end=N;
	for(int i=1;i<=pathnum;i++){
		cin>>v1>>v2;
		cin>>t;
		sign[v1][v2]+=t;
		amatrix[v1][v2]+=t;
	}
	while(dealpath());
	cout<<sum<<endl;	
//	print();
	
}
