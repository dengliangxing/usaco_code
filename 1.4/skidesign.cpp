/*
ID: 15256292
LANG: C++ 
TASK: skidesign
*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
ifstream fin("skidesign.in");
ofstream fout("skidesign.out");
int montain[1002];
int h[101];
int n;
long minh=10000000000;
long sum=0;
int hl=17;
int main()
{
	fin>>n;
	for(int i=1;i<=n;i++)
	fin>>montain[i];
	sort(montain+1,montain+1+n);
	if(montain[n]-montain[1]<=17)
	{
		fout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(h[montain[i]]==0)
			h[montain[i]]=i;
	int i=18;
	start=h[montain[1]+i];
	while(start==0)
	{
		i++;
		start=h[montain[1]i];
	}
	int i=18;
	end =h[montain[n]-i];
	while(start==0)
	{
		i++;
		end =h[montain[n]-i];
	}
	if(start>end)
	{
		int	t=start;
		start=end;
		end=t;
	}
	for(i=start;i<=end;i++)
	{
		for(int j=1;j<=n;j++)
			if(montain[j]-montain[i]>17||montain[i]-montain[j]>17)
				sum+=(montain[i]-montain[j]-17)*(montain[i]-montain[j]-17);
			if(sum<minh)
				minh=sum;
			sum=0;
	}
	fout<<minh<<endl;
}
