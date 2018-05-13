/*
ID: 15256292
LANG: C++ 
TASK: milk3
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("milk3.in");
ofstream fout("milk3.out");
int sum=0;
struct cup
{
	int a;
	int b;
	int c; 
};
bool milkm[21][21][21];
bool sign[22];
int A,B,C;
int milkc[23];
void fall(int &a,int &b,int a1,int b1)
{
	if(a==0)
	return;
	if(a>b1-b)
	{
		a=a-(b1-b);
		b=b1;
	}else
	{
		b=b+a;
		a=0;
	}
}
void DFS(cup c)
{
	
	if(milkm[c.a][c.b][c.c])
		return;
	milkm[c.a][c.b][c.c]=true;
	if(c.a==0)
	{
		if(sign[c.c]==false)
		{
			milkc[sum++]=c.c;
			sign[c.c]=true;
		}
	}
	cup c1=c;
	fall(c1.a,c1.b,A,B);
	DFS(c1);
	c1=c;
	fall(c1.a,c1.c,A,C);
	DFS(c1);
	c1=c;
	fall(c1.b,c1.c,B,C);
	DFS(c1);
	c1=c;
	fall(c1.c,c1.b,C,B);
	DFS(c1);	
	c1=c;
	fall(c1.c,c1.a,C,A);
	DFS(c1);
	c1=c;
	fall(c1.b,c1.c,B,C);
	DFS(c1);

}
int main()
{
	cup c;
	fin>>A>>B>>C;
	c.a=0;
	c.b=0;
	c.c=C;
	DFS(c);
	sort(milkc,milkc+sum);
	for(int i=0;i<sum-1;i++)
		fout<<milkc[i]<<" ";
	fout<<milkc[sum-1]<<endl;
}
