/*
ID:15256292
LANG:C++
TASK:rockers

*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int w[22][22];
int dp[22][22];
int num[22],MAX=0;
int d[22];
int N,T,M;
int main(){
//	freopen("rockers.in","r",stdin);
//	freopen("rockers.out","w",stdout);
	cin>>N>>T>>M;
	for(int i=1;i<=N;i++)
		cin>>num[i];
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j++){
			for(int z=i;z<=j;z++){
				for(int t=T;t>=num[z];t--)
					d[t]=d[t]>d[t-num[z]]+1?d[t]:d[t-num[z]]+1;
			}
			w[i][j]=d[T];
			memset(d,0,sizeof(d));
		}

	for(int i=1;i<=N;i++)
		dp[1][i]=w[1][i];
	for(int i=2;i<=M;i++)
		for(int j=1;j<=N;j++){
			for(int k=1;k<=j;k++)
				dp[i][j]=max(dp[i][j],dp[i-1][k]+w[k+1][j]);
		}
//	for(int i=1;i<=M;i++){
//		for(int j=1;j<=N;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl; 
//	}
	cout<<dp[M][N]<<endl;
			
}

