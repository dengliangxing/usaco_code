/*
ID:15256292
LANG:C++
TASK:stall4
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int amatrix[403][403],begin=0,end=402,N,M,sum,mark[4000];
void init(){
	int num,t;
	cin>>N>>M;
	for(int i=201;i<=200+M;i++)
		amatrix[i][end]=1;
	for(int i=1;i<=N;i++)
		amatrix[0][i]=1;
	for(int i=1;i<=N;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>t;
			amatrix[i][t+200]=1;
		}		
	}	
}
bool findpath(){
	memset(mark,-1,sizeof(mark));
	int qu[406],start=0,rear=0,t;
	qu[rear++]=begin;
	mark[begin]=-2;
	while(start!=rear){
		t=qu[start++];
		for(int i=0;i<=402;i++){
			if(amatrix[t][i]>0&&mark[i]==-1){
				qu[rear++]=i;
				mark[i]=t;
				if(i==end)
					return true;
			 } 
			 
		}
	}
	return false;
}
bool deal_path(){
	if(!findpath())
		return false;
	int t=end;
	while(mark[t]!=-2){
		amatrix[mark[t]][t]-=1;
		amatrix[t][mark[t]]+=1;
		t=mark[t]; 
	}
	
	sum++;
	return true;
}

int main(){
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	init();
	while(deal_path());
	
	cout<<sum<<endl;
}
