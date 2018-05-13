/*
ID: 15256292
LANG:C++
TASK:zerosum
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
char ch[20];
int s;
char fu[]=" +-";
int N;
int check(){
	int t=0;
	int i;
	int sum=0;
	char c='#';
	for( i=0;ch[i]!='\0';i++)
		if(ch[i]<='9'&&ch[i]>='1')
			t=t*10+ch[i]-'0';
		else if(ch[i]=='-'||ch[i]=='+')
		{
			switch(c){
				case '+':sum=sum+t;break;
				case '-':sum=sum-t;break;
				case '#':sum=t;
			}
			c=ch[i];
			t=0;
		}
	switch(c){
				case '+':sum=sum+t;break;
				case '-':sum=sum-t;break;
				case '#':sum=t;break;
			}
	return sum;
		
}
void DFS(int n,int sum){
	if(n==N+1)
	{
		
		if(check()==0)
			fout<<ch<<endl; 
		return;
	}
	for(int i=0;i<3;i++)
	{
		ch[sum++]=fu[i];
		ch[sum++]='0'+n;
		DFS(n+1,sum);
		sum-=2;
		
	}
 } 
 int main()
 {
 	fin>>N;
 	
	ch[0]='1';
	DFS(2,1);
	return 0;
 }
