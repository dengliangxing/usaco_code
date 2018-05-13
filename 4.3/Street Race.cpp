/*
ID:15256292
LANG:C++
TASK:race3

*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int g[52][52],g1[52][52],num1[52],num2[52];
int N=0;
bool sign[52];
void DFS(int v){
	for(int i=0;i<=N;i++)
		if(g[v][i]==1&&sign[i]==0){
			sign[i]=1;
			DFS(i);
		}
}
void DFS1(int v){
	for(int i=0;i<=N;i++)
		if(g1[v][i]&&sign[i]==0){
			sign[i]=1;
			DFS1(i);
		}
}
void DFS2(int v){
	for(int i=0;i<=N;i++)
		if(g[v][i]&&sign[i]==0){
			sign[i]=1;
			DFS2(i);
		}
}
int main(){
	freopen("race3.in","r",stdin);
	freopen("race3.out","w",stdout);
	int t,j;
	cin>>t;
	while(t!=-1){
		while(t!=-2){
			g[N][t]=1;
			g1[N][t]=1;
			g1[t][N]=1;
			cin>>t;
		}
		N++;
		cin>>t;
	}
	N--;
	for(int i=1;i<N;i++){
		sign[0]=1;
		sign[i]=1;
		DFS(0);
		if(sign[N]==0)
			num1[++num1[0]]=i;
		memset(sign,0,sizeof(sign));
		sign[0]=1;
		sign[i]=1;
		DFS1(0);
		if(sign[N]==0){
			for(j=0;j<=N;j++)
				if(g[i][j]){
					memset(sign,0,sizeof(sign));
					sign[i]=1;
					sign[j]=1;
					DFS2(j);
					if(sign[N]==0)
						break;
				}
			if(j==N+1)
				num2[++num2[0]]=i;
		}
		memset(sign,0,sizeof(sign));
	}
	cout<<num1[0];
	for(int i=1;i<=num1[0];i++)
		cout<<" "<<num1[i];
	cout<<endl;
	cout<<num2[0];
	for(int i=1;i<=num2[0];i++)
		cout<<" "<<num2[i];
	cout<<endl;
} 
