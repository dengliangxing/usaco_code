/*
ID: 15256292
LANG: C++ 
TASK: transform
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("transform.in");
ofstream fout("transform.out");
#define MAXN 20
struct V
{
	char ch[MAXN][MAXN];
};
V v;
int n;
V turn_90(V vv)
{
	V v1;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			v1.ch[i][j]=vv.ch[n-1-j][i];
	return v1;
}
V mirror(V vv)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n/2;j++)
		{
			char t = vv.ch[i][j];
			vv.ch[i][j]=vv.ch[i][n-1-j];
			vv.ch[i][n-1-j]=t;
		}
		return vv;
}
bool cmp(V a,V b)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a.ch[i][j]!=b.ch[i][j])
				return false;
				return true;
}
int main()
{
	V v1;
	fin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin>>v1.ch[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin>>v.ch[i][j];
	V v2=turn_90(v1);
	V v3=turn_90(v2);
	V v4=turn_90(v3);
	V vm1=mirror(v1);
	V vm2=turn_90(vm1);
	V vm3=turn_90(vm2);
	V vm4=turn_90(vm3);
	if(cmp(v2,v))
		fout<<1<<endl;
	else if(cmp(v3,v))
		fout<<2<<endl;
	else if(cmp(v,v4))
		fout<<3<<endl;
	else if(cmp(v,vm1))
		fout<<4<<endl;
	else if(cmp(v,vm2)||cmp(v,vm3)||cmp(v,vm4))
		fout<<5<<endl;
	else if(cmp(v,v1))
		fout<<6<<endl;
	else
		fout<<7<<endl;
	
}
