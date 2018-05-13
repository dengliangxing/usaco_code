/*
ID: 15256292
LANG: C++ 
TASK: crypt1
*/
#include <iostream>
#include <fstream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");
bool ch[10];
int c[20];
int n;
int Sum=0;
int init()
{
	for(int i=0;i<10;i++)
		ch[i]=false;
	fin>>n;
	for(int i=0;i<n;i++)
	{
		fin>>c[i];
		ch[c[i]]=true;
	}
 } 
 bool check(int n1)
 {
 	int c1[10];
 	int I=0;
 	while(n1!=0)
 	{
 		c1[I++]=n1%10;
 		n1=n1/10;
	 }
 		for(int i=0;i<I;i++)
 		if(ch[c1[i]]==false)
		 return false;
	return true; 
 }
 int main()
 {
 	init();
 		for(int i2=0;i2<n;i2++)
 			for(int i3=0;i3<n;i3++)
 				for(int i4=0;i4<n;i4++)
 				{
 					int sum=c[i2]*100+c[i3]*10+c[i4];
 					for(int j1=0;j1<n;j1++)
 						for(int j2=0;j2<n;j2++)
 						{
 							if(sum*(c[j1]*10+c[j2])<10000)
 								{
								 if(sum*c[j1]<1000&&sum*c[j2]<1000)
 									if(check(sum*c[j1])&&check(sum*c[j2])&&check(sum*(c[j1]*10+c[j2])))
 									Sum++;
 								if(sum*c[j1]>1000&&sum*c[j2]>1000)
 									if(check(sum*c[j1])&&check(sum*c[j2])&&check(sum*(c[j1]*10+c[j2])))
 									Sum++;
							 	}
						 }
				 }
	fout<<Sum<<endl;
 }
