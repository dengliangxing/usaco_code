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
int n;
long minh=10000000000;
long sum=0;
int main()
{
	float i;
	int i1;
	fin>>n;
	for( i1=1;i1<=n;i1++)
	fin>>montain[i1];
	for(i=0.5;i<=100;i++)
	{
		for(int j=1;j<=n;j++)
			if(montain[j]-i>8.5)
				sum+=(montain[j]-i-8.5)*(montain[j]-i-8.5);
			else if(i-montain[j]>8.5)
				sum+=(i-montain[j]-8.5)*(i-montain[j]-8.5);
			if(sum<minh)
				minh=sum;
		sum=0;
	}
	fout<<minh<<endl;
}
