/*
ID: 15256292
LANG: C++ 
TASK: ride
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("ride.in");
ofstream fout("ride.out");
char ch[100];
void init()
{
	for (int i =0;i<100;i++)
	ch[i]='\0';
}
int main()
{
		int i=0;
		int sum=1;
		int sum2=1;
		fin>>ch;
		while(ch[i]!='\0')
		{
			sum = sum*(ch[i]-'A'+1);
			i++;
		}
		sum = sum%47;
		i=0;
		init();
		fin>>ch;
		while(ch[i]!='\0')
		{
			sum2 = sum2*(ch[i]-'A'+1);
			i++;
		}
		sum2=sum2%47;
		if(sum==sum2)
		fout<<"GO"<<endl;
		else
		fout<<"STAY"<<endl;

	
 } 
