/*
ID:15256292
LANG:C++
TASK:prefix
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");
struct Str{
	string str;
	int len;	
};
Str str[1200]; 
bool mark[200002];
char ch[200002];
char cc[100];
int len;
int sum=0;
void issame(int begin)
{
	int i,j;
	for(i=0;i<sum;i++)
	{
		if(mark[begin+str[i].len-1]==false){
			for(j=0;j<str[i].len;j++)
				if(str[i].str[j]!=ch[begin+j])
					break;
			if(j==str[i].len)
			 	mark[begin+j-1]=true;
		}
		
	}
	
}
int main()
{
	string str1;
	while(fin>>str1&&str1!="."){
		str[sum].str=str1;
		str[sum++].len=str1.length();
	}
	char temp;
	while(fin.getline(cc,100)){
		strcat(ch,cc);
		memset(cc,'\0',sizeof(cc));
	}
	int begin=-1;
	for(begin;begin<200002;begin++) 
		if(mark[begin]||begin==-1)
			issame(begin+1);
	int max1=0;
	for(int i=0;i<200002;i++)
		if(mark[i])
		 max1=i+1;
	fout<<max1<<endl;
}
