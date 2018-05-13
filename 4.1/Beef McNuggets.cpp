/*
ID:15256292
LANG:C++
TASK:nuggets

*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
#define INF 100000000
int num[15];
int MIN=INF;
bool dp[65555];
int check(int a,int b){
	while(a!=0&&b!=0){
		int t=a%b;
		a=b;
		b=t;
	}
	return a+b;
}
int main(){
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout); 
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>num[i];
	for(int i=1;i<N;i++)
		for(int j=i+1;j<=N;j++){
			if(check(num[i],num[j])==1&&MIN>num[i]*num[j]-num[i]-num[j])
				MIN=num[i]*num[j]-num[i]-num[j];
	}
	if(MIN==INF){
		cout<<0<<endl;
		return 0;
	}	
	dp[0]=1;
	for(int i=1;i<=N;i++)
		for(int j=0;j<=MIN-num[i];j++)
			if(dp[j]==1)
				dp[j+num[i]]=dp[j];	
	int i,t;	
	for(int i=MIN;i>0;i--)
		if(dp[i]==0){
			t=i;
			break;
		}
	cout<<t<<endl;
	return 0;
			
}

