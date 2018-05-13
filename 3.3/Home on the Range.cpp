/*
ID: 15256292
LANG:C++
TASK:range
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int num[30][253][253];
int N,sum=0,cun,sum1;
bool BFS(int I,int J){
	if(num[cun][I][J]==4)
		sum1++;
	for(int i=I;i<I+2;i++)
		for(int j=J;j<J+2;j++)
			if(num[cun][i][j]!=4)
				return false;
			
	sum++;			
	for(int i=I;i<I+2;i++)
		for( int j=J;j<J+2;j++)
			num[(cun+1)%20][i][j]++;
	return true;
}
void print(int n){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			cout<<num[n][i][j]<<" ";
		cout<<endl;
	}
			
}
void init(){
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			char ch;
			cin>>ch;
			if(ch=='1') 
				num[0][i][j]=4;
			else
				num[0][i][j]=0;
		}	
	for(int z=2;z<=N;z=z+2){
		memset(num[(cun+1)%20],0,sizeof(num[(cun+1)%20]));
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				BFS(i,j);
		cun=(cun+1)%20;
		if(z!=2&&sum1!=0)
			cout<<z-1<<" "<<sum1<<endl; 
		if(sum==0&&sum1==0)
			break;
		if(sum!=0)
			cout<<z<<" "<<sum<<endl;
		sum=0;	
		sum1=0;
	}
	
					
}
int main(){
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	init();
	return 0;
}
