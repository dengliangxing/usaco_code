/*
ID: 15256292
LANG: C++ 
TASK: milk2
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("milk2.in");
ofstream fout("milk2.out");
struct T
{
	long begin;
	long end;
};
int cmp(T a,T b)
{
	if(a.begin<b.begin)
		return true;
	else if(a.begin==b.begin)
		return a.end>b.end;
	else 
		return false;
	
}
int N;
T t[5050];
T t1[5050];
long maxtn=0,maxty=0;
int main()
{
	fin>>N;
	for(int i=0;i<N;i++)
		fin>>t[i].begin>>t[i].end;
	sort(t,t+N,cmp);
	int sign=t[0].begin;
	int sum=0;
	t1[sum].begin=t[0].begin;
	t1[sum++].end=t[0].end;
	for(int i=0;i<N;i++)
	{
		if(sign!=t[i].begin)
		{
			t1[sum].begin=t[i].begin;
			t1[sum++].end=t[i].end;
			sign=t[i].begin;
		}
	}
	int end=t1[0].end;
	int maxty1=t1[0].end-t1[0].begin;
	for(int i=0;i<sum-1;i++)
	{
		if(end>=t1[i+1].begin)
		{
			if(end<t1[i+1].end)
			{
				maxty1+=t1[i+1].end-end;
				end=t1[i+1].end;
			}
		}	
		else
		{
			if(maxty<maxty1)
				maxty=maxty1;
			maxty1=t1[i+1].end-t1[i+1].begin;
			int end1 = end;
			end = t1[i+1].end;
			if(end1<t1[i].end)
				end1 = t1[i].end;
			if(maxtn<t1[i+1].begin-end1)
				maxtn=t1[i+1].begin-end1;
		}
	}
	if(maxty1>maxty)
		maxty=maxty1;
	if(sum==1)
	fout<<t1[0].end-t1[0].begin<<" "<<0<<endl; 
	else
	fout<<maxty<<" "<<maxtn<<endl; 

}
