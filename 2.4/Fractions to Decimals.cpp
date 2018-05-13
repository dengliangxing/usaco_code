/*
ID:15256292
LANG:C++
TASK:fracdec
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int mark[100001];
int sum=1;
char ch[20000];
int rest[100001];
char num[100001];
char Str[100001];
char str[10];
int main(){
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	int N,D;
	cin>>N>>D;
	if(N%D==0){
		cout<<N/D<<".0"<<endl;
		return 0;
	} 
	 
	sprintf(str,"%d.",N/D);
	strcat(Str,str);
	
	int SUM=strlen(Str);
	int t=0;
	rest[sum]=N%D;
	while(true){
		
		if(rest[sum]==0){
			t=1;
			break;
		}
		if(mark[rest[sum]]!=0)
			break;
		mark[rest[sum]]=sum;
		num[sum]=rest[sum]*10/D+'0';
		rest[sum+1]=rest[sum]*10%D;
		sum++;
	}
	if(t){
		for(int i=1;i<sum;i++)
			Str[SUM++]=num[i];
	}else{
		for(int i=1;i<mark[rest[sum]];i++)
			Str[SUM++]=num[i];
		Str[SUM++]='(';
		for(int i=mark[rest[sum]];i<sum;i++)
			Str[SUM++]=num[i];
		Str[SUM++]=')';
	}
	for(int i=0;i<SUM;i++)
		if(i%76==0&&i!=0)
			cout<<endl<<Str[i];
		else
			cout<<Str[i];
	if(SUM%76!=0)
		cout<<endl;
}
