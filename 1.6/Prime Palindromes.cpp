/*
ID: 15256292
LANG: C++ 
TASK: pprime
*/
#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
ifstream fin("pprime.in");
ofstream fout("pprime.out");
int a,b;
int s[]={5,7,11};
int NUM[15555];
int sum=0;
int dao(int n,int &a)
{
	a=0;
	int t[10];
	for(int i=0;i<10;i++)
		t[i]=0;
	while(n!=0)
	{
		t[a++]=n%10;
		n=n/10;
	}
	int st=0;
	for(int i=0;i<a;i++)
		st=st*10+t[i];
	return st;
}
bool isPrime(long num)
{
	for(int i=2;i<=sqrt(num);i++)
	if(num%i==0)
		return false;
		return true;
 } 
int getnum()
{
	for(int i=0;i<3;i++)
	if(a<=s[i]&&s[i]<=b)
		NUM[sum++]=s[i];
	for(int i=0;i<=9;i++)
	{
		for(int j=1;j<=999;j++)
		{
			int l;
			int n1=dao(j,l);
			int st=j*pow(10,l+1)+i*pow(10,l)+n1;
			if(st>=a&&st<=b&&st%2!=0&&st%3!=0)
				if(isPrime(st))
					NUM[sum++]=st;
		}
	}
}
 int main()
 {
 	fin>>a>>b;
 	getnum();
 	sort(NUM,NUM+sum);
 	for(int i=0;i<sum;i++)
 		fout<<NUM[i]<<endl;
 
 	
 }
