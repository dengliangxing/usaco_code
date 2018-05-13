/*
ID:15256292
LANG:C++
TASK:humble
*/ 
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define INF 100000000000
int index[101];
int num[102];
long long S[100008];
long long N,K,min1=INF,t;
int main(){
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	cin>>K>>N;
	for(int i=1;i<=K;i++)
		cin>>num[i];
	S[0]=1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=K;j++){
			while(S[index[j]]*num[j]<=S[i-1])
				index[j]++;
			if(min1>S[index[j]]*num[j]){
				min1=S[index[j]]*num[j];
				t=j;
			}	
		}
		S[i]=min1;
			index[t]++;
			min1=INF;
	}
	cout<<S[N]<<endl;
}
