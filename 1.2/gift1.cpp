/*
ID: 15256292
LANG: C++ 
TASK: gift1
*/
#include<iostream>
#include<fstream>
#include<map> 
using namespace std;
struct people
{
	string name;
};
people pp[20];
ifstream fin("gift1.in");
ofstream fout("gift1.out");
int main()
{
	map<string,int> p;
	int num;
	string sendname;
	int money,pnum;
	string name;
	fin>>num;
	for(int i=0;i<num;i++)
	{
		fin>>name;
		pp[i].name=name;
		p.insert(pair<string,int>(name,0));
	}
	for(int i=0;i<num;i++)
	{
		fin>>sendname>>money>>pnum;
		if(pnum==0)
		continue;
		p[sendname]=p[sendname]-money/pnum*pnum;
		for(int j=0;j<pnum;j++)
		{
			fin>>name;
			p[name]=p[name]+money/pnum;
		}
	}
	map<string, int>::iterator  iter; 
	for(int i=0;i<num;i++)
	fout<<pp[i].name<<" "<<p[pp[i].name]<<endl;
}
