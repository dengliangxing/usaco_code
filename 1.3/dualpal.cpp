/*
ID: 15256292
LANG: C++ 
TASK: dualpal
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");
char *ch="ABCDEFGHIJKLMN";
char ch1[200];
int I=0;
bool check(int num,int n)
{
	I=0;	
	int j;
	while(num!=0)
	{
		ch1[I++]=num%n;
		num=num/n;
	}
	for( j=0;j<I/2;j++)
		if(ch1[j]!=ch1[I-1-j])
			{
				I=0;
				return false;
			}
	return true;
		
}
bool f(int nu)
{
	int num=0;
	for(int i=2;i<=10;i++)
	{
		if(check(nu,i))
			num++;
		if(num>=2)
			return true;
	}
	return false;
}
int main()
{
	int S;
	int N;
	int sum=0;
    fin>>N>>S;
    S++;
    while(sum<N)
    	{
    		if(f(S))
    		{
				fout<<S<<endl;
    			sum++;
    		}
    		S++;
		} 	 
}
