/*
ID: 15256292
LANG:C++
TASK:game1
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int min(int a,int b){
	if(a<b)
		return a;
	return b;
}
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
void init(){
	int num[500];
	int N,sum1=0,sum2=0;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>num[i];
		if(i%2==1)
			sum1+=num[i];
		else
			sum2+=num[i];
	}
	cout<<sum1<<" "<<sum2<<endl;
	if(N%2==0){
		if(sum1>sum2)
			cout<<sum1<<" "<<sum2<<endl;
		else
			cout<<sum2<<" "<<sum1<<endl;
	}
	else{
		int sum = max(num[1]+min(sum1-num[1],sum2),num[N]+min(sum1-num[N],sum2));
		cout<<sum<<" "<<sum1+sum2-sum<<endl;
	}
		 
}
int main(){
	freopen("game1.in","r",stdin);
//	freopen("game1.out","w",stdout);
	init();
	return 0;
}
