/*
ID: 15256292
LANG: C++ 
TASK: milk
*/
#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("milk.in");
ofstream fout("milk.out");
struct P
{
	long num;
	int money;
};
P p[5002];
int pnum;
int pmilk;
bool cmp(P a,P b)
{
	return a.money<b.money;
}
void init()
{
	fin>>pmilk>>pnum;
	for(int i =0;i<pnum;i++)
		fin>>p[i].money>>p[i].num;
	sort(p,p+pnum,cmp);
}
int main()
{
	long summoney=0;
	int i=0;
	init();
	while(pmilk>0)
	{
		if(pmilk>p[i].num)
			summoney+=p[i].num*p[i].money;
		else
			summoney+=p[i].money*pmilk;
		pmilk-=p[i].num;
		i++;
	}
	fout<<summoney<<endl;
}
