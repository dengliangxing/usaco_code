/*
ID: 15256292
LANG: C++
TASK: comehome
*/
#include<iostream>
#include<fstream>
using namespace std;
#define INF 1000000
ifstream fin("comehome.in");
ofstream fout("comehome.out");
int map[100][100];
void init(){
	for(int i=1;i<=52;i++)
		for(int j=1;j<=52;j++)
			if(i!=j)
				map[i][j]=INF;
}
int convert(char a){
	if(a<='z'&& a>='a')
		return a-'a'+1;
	else
		return a-'A'+27;
}
int print()
{
	for(int i=1;i<=52;i++){
		for(int j=1;j<=52;j++)
			fout<<map[i][j]<<"\t";
		fout<<endl;
	}
}
int main(){
	int N;
	char v1,v2,p;
	int min1=INF,t;
	init();
	fin>>N;
	for(int i=1;i<=N;i++){
		fin>>v1>>v2;
		fin>>t;
		if(map[convert(v1)][convert(v2)]>t){
		
			map[convert(v1)][convert(v2)]=t;
			map[convert(v2)][convert(v1)]=t;
		}
	}
	for(int k=1;k<=52;k++)
		for(int i=1;i<=52;i++)
			for(int j=1;j<=52;j++)
				if(map[i][j]>map[i][k]+map[k][j])
					map[i][j]=map[i][k]+map[k][j];
	for(int i=27;i<52;i++)
		if(min1>map[i][52]){
			min1=map[i][52];
			p=i-27+'A';
		}
		fout<<p<<" "<<min1<<endl;
	
}
