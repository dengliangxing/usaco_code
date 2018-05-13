/*
ID: 15256292
LANG: C++ 
TASK: preface
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<math.h>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");
int sum1[]={0,1,3,6,7,7,8,10,13,14};
int num1[]={0,1,2,3,1,0,1,2,3,1};
int sum2[]={0,0,0,0,1,2,3,4,5,5};
int num2[]={0,0,0,0,1,1,1,1,1,0};
int sum3[]={0,0,0,0,0,0,0,0,0,1};
char *ch="IXCM";
char *ch1="VLD";
int main()
{
	int sum=0,s=0,s1=0,n=0;
	fin>>n;
	while(n!=0)
	{
		int t=n%10;
		n/=10;
		int z1=	n*sum1[9]*pow(10,sum)+sum1[t-1]*pow(10,sum)+num1[t]*(s+1)+s1;
		int z2= n*sum2[9]*pow(10,sum)+sum2[t-1]*pow(10,sum)+num2[t]*(s+1);
		s1=n*sum3[9]*pow(10,sum)+sum3[t-1]*pow(10,sum)+sum3[t]*(s+1);
		s+=t*pow(10,sum);
		if(z1!=0)
		fout<<ch[sum]<<" "<<z1<<endl;
		if(z2!=0)
		fout<<ch1[sum]<<" "<<z2<<endl;
		sum++;
	}
	if(s1!=0)
		fout<<ch[sum]<<" "<<1<<endl;
}
