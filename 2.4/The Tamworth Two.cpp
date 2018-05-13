/*
ID:15256292
LANG:C++
TASK:ttwo
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
char ch[11][11];
int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};
void move(int &I,int &J,int &t)
{
	int i=I+x[t];
	int j=J+y[t];
	if(i>0&&i<=10&&j>0&&j<=10&&ch[i][j]=='.'){
		I=i;
		J=j;
	}else t=(t+1)%4; 
 } 
 int main()
 {
	int ci,cj,fi,fj,ct=0,ft=0;
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++){
			fin>>ch[i][j];
			if(ch[i][j]=='F'){
				fi=i;
				fj=j;
				ch[i][j]='.';
			}
			if(ch[i][j]=='C'){
				ci=i;
				cj=j;
				ch[i][j]='.';
			}
		}
	for(int i=1;i<=160000;i++){
		move(ci,cj,ct);
		move(fi,fj,ft);
		if(fi==ci&&fj==cj)
		{
			fout<<i<<endl;
			return 0;
		}
	}
	fout<<"0"<<endl;
 }
