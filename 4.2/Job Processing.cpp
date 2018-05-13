/*
ID:15256292
LANG:C++
TASK:job
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define INF 1000000
int N,M1,M2,A[31],B[31],MIN;
int anum[31],bnum[31],aend[3000],bend[3000]; 
void init(){
	cin>>N>>M1>>M2;
	for(int i=1;i<=M1;i++)
		cin>>A[i];
	for(int i=1;i<=M2;i++)
		cin>>B[i];
} 
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int main(){
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	int MAX=0,MIN1=INF;
	init();
	int t,b1,b2;
	for(int i=1;i<=N;i++){
		MIN=INF;
		for(int a=1;a<=M1;a++)
			if(MIN>anum[a]+A[a]){
				MIN=anum[a]+A[a];
				t=a;
			}
		anum[t]=MIN;
		aend[i]=MIN;
		MIN1=INF;	
	}
	MIN1=INF;
	for(int i=1;i<=N;i++){
		MIN=INF;
		for(int b=1;b<=M2;b++)
			if(MIN>bnum[b]+B[b]){
				MIN=bnum[b]+B[b];
				t=b;
			}
		bnum[t]=MIN;
		bend[i]=MIN;
		MIN1=INF;	
	}
	sort(&aend[1],&aend[1]+N);
	sort(&bend[1],&bend[1]+N);
	for(int i=1;i<=N;i++)
		if(MAX<aend[i]+bend[N-i+1])
			MAX=aend[i]+bend[N-i+1];
			
	cout<<aend[N]<<" "<<MAX<<endl; 
}
