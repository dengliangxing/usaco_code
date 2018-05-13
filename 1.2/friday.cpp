/*
ID: 15256292
LANG: C++ 
TASK: friday
*/
#include<iostream>
#include<fstream>
#include<map> 
using namespace std;
ifstream fin("friday.in");
ofstream fout("friday.out");
int main()
{	int week[7];
	for(int i=0;i<7;i++)
	week[i]=0;
	int month[]={0,12,31,28,31,30,31,30,31,31,30,31,30};
	int firstyear=1900;
	int firstday=1;
	int n;
	fin>>n;
	for (int i=0;i<n;i++)
	{
		if((firstyear+i)%100==0)
		{
			if((firstyear+i)%400==0)
				month[3]=29;
			else
				month[3]=28;
		}
		else if((firstyear+i)%4==0)
			month[3]=29;
		else
			month[3]=28;
		for(int j=1;j<=12;j++)
		{
			week[(firstday+month[j])%7]++;
			firstday=firstday+month[j]%7;
		}
		firstday=(19+firstday)%7;
	}
	fout<<week[6]<<" ";
	for(int i=0;i<5;i++)
		fout<<week[i]<<" ";
		fout<<week[5]<<endl;
}
