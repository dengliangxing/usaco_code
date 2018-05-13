/*
ID: 15256292
LANG: C++ 
TASK: namenum
*/
#include<iostream>
#include<fstream>
#include<map> 
using namespace std;
int num[120];
char ch[26][26][26][26];
ifstream fin1("dict.txt");
ifstream fin("namenum.in");
ofstream fout("namenum.out");
char s1[4],s2[4],s3[4],s4[4];
int main()
{
	num['A']=num['B']=num['C']=2;
	num['D']=num['E']=num['F']=3;
	num['G']=num['H']=num['I']=4;
	num['J']=num['K']=num['L']=5;
	num['M']=num['N']=num['O']=6;
	num['P']=num['R']=num['S']=7;
	num['T']=num['U']=num['V']=8;
	num['X']=num['Y']=num['W']=9;
	char s[10];
	while(fin1>>s)
			ch[s[0]-'A'][s[1]-'A'][s[2]-'A'][s[3]-'A']=2;
	fin>>s;
	int num1=0,num2=0,num3=0,num4=0;
		for(int j=0;j<120;j++)
			{
				if(num[j]==s[0]-'0')
					s1[num1++]=j;
					if(num[j]==s[1]-'0')
					s2[num2++]=j;
					if(num[j]==s[2]-'0')
					s3[num3++]=j;
					if(num[j]==s[3]-'0')
					s4[num4++]=j;
			}
	cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
	for(int i1=0;i1<3;i1++)
		for(int i2=0;i2<3;i2++)
			for(int i3=0;i3<3;i3++)
				for(int i4=0;i4<3;i4++)
					if(ch[s1[i1]-'A'][s2[i2]-'A'][s3[i3]-'A'][s4[i4]-'A']==2)
						fout<<s1[i1]<<s2[i2]<<s3[i3]<<s4[i4]<<endl;
}
