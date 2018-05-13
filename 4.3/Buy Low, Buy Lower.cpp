/*
ID:15256292
LANG:C++
TASK:buylow
*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define INF 2147483647
struct big_number{
	short num[500];
	int size;
	big_number(){
		size=0;
		memset(num,0,sizeof(num));
	}
	big_number operator+(big_number &number){
		int t=0;
		int msize=max(size,number.size);
		big_number new1;
		for(int i=1;i<=msize;i++){
			new1.num[i]=(num[i]+number.num[i]+t)%10;
			t=(num[i]+number.num[i]+t)/10;
		}
		if(t>0){
			new1.size=msize+1;
			new1.num[msize+1]=t;
		}else
			new1.size=msize;
		return new1;
	}
};
struct node{
	long price;
	big_number sum;
	int n;
}; 
node num[5002];
int main(){
	freopen("buylow.in","r",stdin);
	freopen("buylow.out","w",stdout);
	int N,MAX=0,t1=0;
	cin>>N;
	num[0].price=INF;
	long t;
	for(int i=1;i<=N;i++){
		cin>>t;
		num[i].price=t;
		for(int j=0;j<i;j++)
			if(num[j].price!=-1&&num[j].price>t&&MAX<num[j].n+1)
				MAX=num[j].n+1; 
		num[i].n=MAX;
		for(int j=1;j<i;j++)
			if(num[j].price==t&&num[j].n==MAX)
				num[j].price=-1;
		for(int j=1;j<i;j++)
			if(num[j].price!=-1&&num[j].price>t&&num[j].n==MAX-1)
				num[i].sum=num[i].sum+num[j].sum;
		if(num[i].sum.size==0){
			num[i].sum.size=1;
			num[i].sum.num[1]=1;
		}	
		MAX=0;
	}
	for(int j=1;j<=N;j++)
		if(num[j].price!=-1&&num[j].price>t1&&MAX<num[j].n+1)
				MAX=num[j].n+1;
	num[N+1].n=MAX;
	for(int j=1;j<=N;j++)
		if(num[j].price!=-1&&num[j].n==MAX-1)
			num[N+1].sum=num[N+1].sum+num[j].sum;
	cout<<num[N+1].n-1<<" ";
	for(int i=num[N+1].sum.size;i>0;i--)
		cout<<num[N+1].sum.num[i];
		cout<<endl; 
}
