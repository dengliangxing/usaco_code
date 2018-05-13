/*
ID: 15256292
LANG:C++
TASK:money
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
long long money[10005];
int main(){
	int V,N;
	int t;
	fin>>V>>N;
	money[0]=1;
	for(int i=1;i<=V;i++){
		fin>>t;
		for(int j=t;j<=N;j++)
			money[j]+=money[j-t];
	}
	fout<<money[N]<<endl;
	 
	
}
