/*
ID:15256292
LANG:C++
TASK:lamps
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int check[4][6]={{1,1,1,1,1,1},{1,0,1,0,1,0},{0,1,0,1,0,1},{1,0,0,1,0,0}};
bool markon[6];
bool markoff[6];
bool mark[1000];
int NUM;
int N,C;
void print(int n)
{
	for(int i=0;i<6;i++)
		if(n&(1<<(5-i)))
			cout<<1;
		else
			cout<<0;
	cout<<endl;
}
bool isTrue(int n)
{
	//print(n);
	for(int i=0;i<6;i++){
	
		if(markon[i]){
			if(!(n&(1<<(5-i))))
				return false;
		}
		if(markoff[i]){
			if(n&(1<<(5-i)))
				return false;
		}
	}
	return true;
}
void DFS(int n,int num,int t)
{
	//print(t);
	if(num==NUM){
		if(isTrue(t))
			mark[t]=true;
		return;	
	}
	if(n==4)
		return ;
	DFS(n+1,num,t);
	for(int i=0;i<6;i++){
		if(check[n][i])
			if(t&(1<<(5-i)))
				t-= (1<<(5-i));
			else
				t+=(1<<(5-i));
	}
	
	DFS(n+1,num+1,t);
	
}
int main(){
	fin>>N>>C;
	int t;
	fin>>t;
	while(t!=-1){
		markon[(t-1)%6]=true;
		fin>>t;
	}
	fin>>t;
	while(t!=-1){
		markoff[(t-1)%6]=true;
		fin>>t;
	}
	int i=C%2;
	for(i;i<=4&&i<=C;i+=2){
		NUM=i;
		DFS(0,0,63);
	 }
	t=0;
	for(int i=0;i<1000;i++)
		if(mark[i])
		{
			for(int j=0;j<N;j++)
				if(i&(1<<5-(j%6)))
					fout<<1;
				else
					fout<<0;
			fout<<endl;
			t=1;
		 } 
	if(t==0)
		fout<<"IMPOSSIBLE"<<endl;
}
