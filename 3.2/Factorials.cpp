/*
ID:15256292
LANG:C++
TASK:fact4
*/ 
#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("fact4.in");
ofstream fout("fact4.out");
int sum[10];
int f(int n,int t){
	while(n%t==0){
		sum[t]++;
		n/=t;
	}
	return n;
}
int main(){
	int N;
	fin>>N;
	int sum1=1;
	for(int i=1;i<=N;i++)
		sum1=(sum1*f(f(i,5),2))%10;
//	cout<<sum1;
	for(int i=1;i<=sum[2]-sum[5];i++)
		sum1=(sum1*2)%10;
	fout<<sum1<<endl;
}
