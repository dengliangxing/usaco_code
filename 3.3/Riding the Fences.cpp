/*
ID:15256292
LANG:C++
TASK:fence
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct point{
	int i,j;
};
int num[2000];
int path[501][501];
int pathl[501][501];
int pathnum[501];
int MAX,top=0,MIN=502,N,cpath[501][501],sum=0;
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
bool cmp(int a,int b){
	return a<b;
}
void init(){
	int v1,v2;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>v1>>v2;
		MAX=max(MAX,max(v1,v2));
		path[v1][pathnum[v1]++]=v2;
		path[v2][pathnum[v2]++]=v1;
		pathl[v1][v2]++;
		pathl[v2][v1]++;
	}
	for(int i=1;i<=MAX;i++)
		sort(path[i],path[i]+pathnum[i],cmp);
	for(int i=1;i<=MAX;i++)
		if(pathnum[i]%2==1){
			MIN=i;
			return ;
		}
	
}
void copy(){
	for(int i=1;i<=MAX;i++)
		for(int j=1;j<=MAX;j++)
			cpath[i][j]=pathl[i][j];
}
void print(){
	for(int i=0;i<=N;i++)
		cout<<num[i]<<endl;
}
bool DFS(int n ){ 
	for(int i=0;i<pathnum[n];i++){
		if(cpath[n][path[n][i]]>0){
			sum++;
			cpath[n][path[n][i]]--;
			cpath[path[n][i]][n]--;
			DFS(path[n][i]);
		}
	}
	return false;
}
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	init();
	if(MIN>500)
		MIN=1;
	num[top++]=MIN;
	int begin=MIN;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=pathnum[begin];j++){
			if(pathl[begin][path[begin][j]]>0){
				pathl[begin][path[begin][j]]--;
				pathl[path[begin][j]][begin]--;
				copy();
				sum=0;
				DFS(path[begin][j]);
				if(sum==(N-i)){
					num[top++]=path[begin][j];
					begin=path[begin][j];
					break;
				}
				pathl[begin][path[begin][j]]++;
				pathl[path[begin][j]][begin]++;
			}
		}
	}
		
	print(); 
	
}
