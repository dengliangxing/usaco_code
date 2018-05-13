/*
ID:15256292
LANG:C++
TASK:shopping
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct  G{
	int id,num,price;
};
struct Cheap{
	G num[6];
	int sum;
	int moeny;
};
Cheap ce[100];
int dp[6][6][6][6][6];
G buy[6];
int mark[1002];
int buynum,cenum,price[6],list[6],begin[6];
void DFS(int n){
	if(n==buynum+1){
		int sum=0;
		for(int i=0;i<=buynum;i++)
			sum+=list[i]*buy[i].price;
		dp[list[1]][list[2]][list[3]][list[4]][list[5]]=sum;
		return ;
	} 
	for(int i=list[i];i<=buy[n].num;i++){
		list[n]=i;
		DFS(n+1);
	}
}
void init(){
	cin>>cenum;
	for(int i=1;i<=cenum;i++){
		cin>>ce[i].sum;
		for(int j=1;j<=ce[i].sum;j++)
			cin>>ce[i].num[j].id>>ce[i].num[j].num;
		cin>>ce[i].moeny;
	}
	cin>>buynum;
	for(int i=1;i<=buynum;i++){
		cin>>buy[i].id>>buy[i].num>>buy[i].price;
		mark[buy[i].id]=i;
	}
	DFS(1);	
}
void DFS1(int n,int cnum){
	if(n==buynum+1){
		if(dp[list[1]][list[2]][list[3]][list[4]][list[5]]>dp[list[1]-begin[1]][list[2]-begin[2]][list[3]-begin[3]][list[4]-begin[4]][list[5]-begin[5]]+ce[cnum].moeny)
			dp[list[1]][list[2]][list[3]][list[4]][list[5]]=dp[list[1]-begin[1]][list[2]-begin[2]][list[3]-begin[3]][list[4]-begin[4]][list[5]-begin[5]]+ce[cnum].moeny;
			return ;
	}
	for(int i=begin[n];i<=buy[n].num;i++){
		list[n]=i;
		DFS1(n+1,cnum);
	}
}
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int num,t=0,i,j;
	init();
	for( i=1;i<=cenum;i++){
		memset(begin,0,sizeof(begin));
		memset(list,0,sizeof(list));
		for( j=1;j<=ce[i].sum;j++){
			if(mark[ce[i].num[j].id]>0){
				begin[mark[ce[i].num[j].id]]=ce[i].num[j].num;
			}
			else
				break;
		}
		if(j==ce[i].sum+1)
			DFS1(1,i);
	}
	cout<<dp[buy[1].num][buy[2].num][buy[3].num][buy[4].num][buy[5].num]<<endl;
}
