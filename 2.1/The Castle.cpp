/*
ID: 15256292
LANG: C++ 
TASK: castle
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("castle.in");
ofstream fout("castle.out");
int hnum[2503];
int num1[]={0,-1,0,1};
int num2[]={-1,0,1,0};
int c[60][60];
int house[60][60];
char c1[]="WNES";
int x,y;
void DFS(int I,int J,int nu)
{
	if(house[I][J]!=0)
		return;
	house[I][J]=nu;
	hnum[nu]++;
	for(int i=0;i<4;i++)
		if(!(c[I][J]&(1<<i)))
			DFS(I+num1[i],J+num2[i],nu);
}
int main()
{
	int nu=1;
	int max=0;
	int x1,y1;
	int a,a1;
	fin>>x>>y;
	for(int i=1;i<=y;i++)
		for(int j=1;j<=x;j++)
			fin>>c[i][j];
	for(int i=1;i<=y;i++)
		for(int j=1;j<=x;j++)
			if(house[i][j]==0)
			{
				DFS(i,j,nu);
				nu++;
			}
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
		{
			for(int z=0;z<4;z++)
				if(house[j][i]!=house[j+num1[z]][i+num2[z]])
					{
						if(max==hnum[house[j][i]]+hnum[house[j+num1[z]][i+num2[z]]]&&i==x1)
						{
							max=hnum[house[j][i]]+hnum[house[j+num1[z]][i+num2[z]]];
							y1=j;
							x1=i;
						}
						else if(max<hnum[house[j][i]]+hnum[house[j+num1[z]][i+num2[z]]])
						{
							max=hnum[house[j][i]]+hnum[house[j+num1[z]][i+num2[z]]];
							y1=j;
							x1=i;
						}	
					}
		}
	int t;
	for(int i=1;i<nu;i++)
		if(a<hnum[i])
			a=hnum[i];
		fout<<nu-1<<endl;
		fout<<a<<endl;
		for(int z=0;z<4;z++)
				if(house[y1][x1]!=house[y1+num1[z]][x1+num2[z]]&&house[y1+num1[z]][x1+num2[z]]!=0&&max==hnum[house[y1][x1]]+hnum[house[y1+num1[z]][x1+num2[z]]])
				{
						t=z;
						break;
				}
		fout<<max<<endl;
		fout<<y1<<" "<<x1<<" "<<c1[t]<<endl;
	return 0;
}
