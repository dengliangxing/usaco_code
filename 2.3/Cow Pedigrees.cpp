/*
ID:15256292
LANG:C++
TASK:nocows
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");
long long dp[300][300];
long long s[300][300];
int main(){
	int N,K;
	fin>>N>>K;
	dp[1][1]=1;
	long long sum1=0,sum2=0,sum3=0;
	for(int i=2;i<=K;i++){
		for(int j=1;j<=N;j+=2){
			for(int k=1;k<=j-1;k+=2)
				if(k!=(j-1-k))
				 	dp[i][j]+=(dp[i-1][k]*dp[i-1][j-k-1]+dp[i-1][k]*s[i-2][j-k-1]+dp[i-1][j-1-k]*s[i-2][k])%9901;
				else
				 	dp[i][j]+=(dp[i-1][k]*dp[i-1][j-k-1]+dp[i-1][k]*s[i-2][j-k-1]+dp[i-1][j-1-k]*s[i-2][k])%9901;
				dp[i][j]%=9901;
			}
  		
  		for(int j=0;j<=N;j++)
  			s[i-1][j]=(s[i-2][j]+dp[i-1][j])%9901;
	}
	fout<<dp[K][N]<<endl;

}
