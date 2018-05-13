/*
ID: 15256292
LANG:C++
TASK:camelot
*/
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
#define INF 1083684
struct pointer{
	int i,j;
};
pointer p[1042];
int map[1041][41][27];
int summap[41][27];
int kmap[10][41][27];
int  C,R;
int pnum;
int MIN=INF;
int mi[]={-2,-1,1,2,2,1,-1,-2};
int mj[]={1,2,2,1,-1,-2,-2,-1};
int ki[]={0,-1,-1,0,1,1,1,0,-1};
int kj[]={0,0,1,1,1,0,-1,-1,-1};
void init(){
	pointer queue[1042];
	int start=0,rear=0;
	for(int i=0;i<=1040;i++)
		for(int j=0;j<=40;j++)
			for(int z=0;z<=26;z++)
				map[i][j][z]=INF;
	for(int i=0;i<=9;i++)
		for(int j=0;j<=40;j++)
			for(int z=0;z<=26;z++)
				kmap[i][j][z]=INF;
	cin>>R>>C;
	int t=R;
	R=C;
	C=t;
	char r;
	int c;
	while(cin>>r>>c){
		p[pnum].i=c;
		p[pnum++].j=r-'A'+1;
//		printf("%d,%c\n",c,r);
	}
	int I,J;
	for(int i=0;i<pnum;i++){
		start=rear=0;
		queue[rear].i=p[i].i;
		queue[rear++].j=p[i].j;
		map[i][p[i].i][p[i].j]=0;
		while(rear!=start){
			I=queue[start].i;
			J=queue[start++].j;
			for(int j=0;j<8;j++)
				if(I+mi[j]>0&&I+mi[j]<=C&&J+mj[j]>0&&J+mj[j]<=R&&map[i][I+mi[j]][J+mj[j]]==INF){
					map[i][I+mi[j]][J+mj[j]]=map[i][I][J]+1;
					queue[rear].i=I+mi[j];
					queue[rear++].j=J+mj[j];
				}			
		}
	}
	for(int i=0;i<9;i++){
		start=rear=0;
		if(p[0].i+ki[i]<=0||p[0].i+ki[i]>C||p[0].j+kj[i]<=0||p[0].j+kj[i]>R)
			continue; 
		queue[rear].i=p[0].i+ki[i];
		queue[rear++].j=p[0].j+kj[i];
		kmap[i][p[0].i+ki[i]][p[0].j+kj[i]]=0;
		while(rear!=start){
			I=queue[start].i;
			J=queue[start++].j;
			for(int j=0;j<8;j++)
				if(I+mi[j]>0&&I+mi[j]<=C&&J+mj[j]>0&&J+mj[j]<=R&&kmap[i][I+mi[j]][J+mj[j]]==INF){
					kmap[i][I+mi[j]][J+mj[j]]=kmap[i][I][J]+1;
					queue[rear].i=I+mi[j];
					queue[rear++].j=J+mj[j];
				}			
		}
	}
	start=rear=0;
		queue[rear].i=p[0].i;
		queue[rear++].j=p[0].j;
		kmap[9][p[0].i][p[0].j]=0;
		while(rear!=start){
			I=queue[start].i;
			J=queue[start++].j;
			for(int j=0;j<=8;j++)
				if(I+ki[j]>0&&I+ki[j]<=C&&J+kj[j]>0&&J+kj[j]<=R&&kmap[9][I+ki[j]][J+kj[j]]==INF){
					kmap[9][I+ki[j]][J+kj[j]]=kmap[9][I][J]+1;
					queue[rear].i=I+ki[j];
					queue[rear++].j=J+kj[j];
				}			
		}
	for(int i=1;i<=C;i++)
		for(int j=1;j<=R;j++)
			for(int z=1;z<pnum;z++)
				summap[i][j]+=map[z][i][j];
}
void judge(int I,int J,int p1){
	for(int i=1;i<=8;i++)
			if(MIN>summap[I][J]-map[p1][I][J]+kmap[i][I][J]+map[p1][p[0].i+ki[i]][p[0].j+kj[i]]+1)
				MIN=summap[I][J]-map[p1][I][J]+kmap[i][I][J]+map[p1][p[0].i+ki[i]][p[0].j+kj[i]]+1;
	if(MIN>summap[I][J]-map[p1][I][J]+map[0][I][J]+map[p1][p[0].i][p[0].j])
		MIN=summap[I][J]-map[p1][I][J]+map[0][I][J]+map[p1][p[0].i][p[0].j];
	if(MIN>summap[I][J]+kmap[9][I][J])
		MIN=summap[I][J]+kmap[9][I][J];
}
void print(int n){
	for(int i=1;i<=C;i++){
		for(int j=1;j<=R;j++)
			cout<<map[n][i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
void kprint(int n){
	for(int i=1;i<=C;i++){
		for(int j=1;j<=R;j++)
			cout<<kmap[n][i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	freopen("camelot.in","r",stdin);
//	freopen("camelot.out","w",stdout);
	init();
	int minp;
//	int p1=268;
	for(int p1=1;p1<pnum;p1++){
		for(int i=1;i<=C;i++)
			for(int j=1;j<=R;j++)
				judge(i,j,p1);
	}
	if(MIN==INF)
		cout<<0<<endl;
	else
		cout<<MIN<<endl;
//	for(int i=0;i<pnum;i++)
//		print(i);
	for(int i=0;i<=9;i++)
		kprint(i);
	return 0;
}
