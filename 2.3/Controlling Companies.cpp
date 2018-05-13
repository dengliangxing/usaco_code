/*
ID: 15256292
LANG:C++
TASK:concom
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream fin("concom.in");
ofstream fout("concom.out");
int v[200][200];
int mark[200][200];
bool markm[202][205][205];
int N;
int max1;
bool m[200];
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
bool s[200];
int DFS(int n)
{
	int t=0;
	for(int i=1;i<=max1;i++)
		if(v[n][i]>50&&mark[n][i]==0&&s[i]==false) {
				mark[n][i]=1;
				s[i]=true;
				t=1;
				DFS(i);
				s[i]=false;
				for(int j = 1;j<=max1;j++)
						if(markm[n][i][j]==false){
							markm[n][i][j]=true;
							v[n][j]+=v[i][j];
						}
			for(int j=1;j<=max1;j++)
				mark[n][j]+=mark[i][j];
		}
	
	
	return t;
}
int main()
{
	fin>>N;
	int v1,v2;
	for(int i=0;i<N;i++){
		fin>>v1>>v2;
		if(max1<max(v1,v2))
			max1=max(v1,v2);
		fin>>v[v1][v2];
	}
	int t=1;
	while(t){
		
		t=0;
		for(int i=1;i<=max1;i++)
		{
			s[i]=true;
			t+=DFS(i);
			s[i]=false;
		}
 }
	for(int i=1;i<=max1;i++)
		for(int j=1;j<=max1;j++)
			if(i!=j&&v[i][j]>50)
				fout<<i<<" "<<j<<endl;
}
