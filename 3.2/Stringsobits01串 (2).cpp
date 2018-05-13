/*
ID:15256292
LANG:C++
TASK:kimbits

*/ 
#include <cstdio>
#include <algorithm>
#include<fstream>
#include<iostream>
using namespace std;
ofstream fout("kimbits.out");
ifstream fin("kimbits.in");
int s[100]; 
long sum=0;
int t=1;
long I;
int N,L;
void DFS(int n,int su){
	if(su>L)
		return ;
	if(n==N){
		sum++;
		if(sum==I){
			for(int i=0;i<N;i++)
				fout<<s[i];
			fout<<endl;
			t=0;
		}
		return ;
	}
	if(t){
	
		DFS(n+1,su);
		if(su+1<=L){
			s[n]=1;
			DFS(n+1,su+1);
			s[n]=0;
		}
	}
}
int main(){
	fin>>N>>L>>I;
	DFS(0,0);
	return 0;
}
