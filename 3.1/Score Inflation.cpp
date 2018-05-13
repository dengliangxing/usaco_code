/*
ID:15256292
LANG:C++
TASK:inflate
*/ 
#include<iostream>
#include<fstream>
using namespace std;
int dp[10001];
int main()
{
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	int minutes,k,cost,score;
	cin>>minutes>>k;
	for(int i=1;i<=k;i++){
		cin>>score>>cost;
		for(int j=cost;j<=minutes;j++)
			dp[j]=dp[j]>dp[j-cost]+score?dp[j]:dp[j-cost]+score;
	}
	cout<<dp[minutes]<<endl;
}
