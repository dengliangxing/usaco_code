/*
ID: 15256292
LANG: C++ 
TASK: ariprog
*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
bool sign[125001];
int n,m;
int t=0;
void init()
{
	fin>>n>>m;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=m;j++)
			sign[i*i+j*j]=true;
	for(int i=1;i<=m*m*2/(n-1);i++)
		for(int j=0;j<=m*m*2-(n-1)*i;j++)
			{
				int z=0;
				for(z=0;z<n;z++)
					if(sign[j+z*i]==false)
						break;	
					if(z==n)
					{
						fout<<j<<" "<<i<<endl;
						t=1;
					}
			}	
}
int main()
{
	init();
	if(!t)
	fout<<"NONE"<<endl;
}
