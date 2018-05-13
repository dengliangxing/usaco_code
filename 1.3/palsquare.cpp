/*
ID: 15256292
LANG: C++ 
TASK: palsquare
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
char *ch="ABCDEFGHIJKLMN";
int n;
char ch1[200];
int I=0;
bool check(int num)
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
void change(int num)
{
	if(num!=0)
	{
		change(num/n);
		int t = num%n;
		if(t<10)
		fout<<t;
		else
		fout<<ch[t-10];
	}
}
void print()
{
	for(int j=0;j<I;j++)
		{
			if(ch1[j]<10)
				fout<<(char)(ch1[j]+'0');
			else
				fout<<(char)(ch[ch1[j]-10]);
		}
		fout<<endl; 
		
}
int main()
{

    fin>>n;
    for(int i=1;i<=300;i++)
    	if(check(i*i))
    	{
    		change(i);
			fout<<" ";
			print();  
		}
}
