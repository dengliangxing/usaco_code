/*
ID: 15256292
LANG:C++
TASK:maze1
*/
#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("maze1.in");
ofstream fout("maze1.out");
int W,H;
char maze[300][300];
int map[300][300];
int x[4]={-1,0,1,0};
int y[4]={0,1,0,-1};
int init()
{
	fin>>W>>H;
	W=W*2+1;
	H=H*2+1;
	char c;
	fin.get(c);
	for(int i=1;i<=H+1;i++)
		for(int j=1;j<=W+1;j++)
			fin.get(maze[i][j]);

}
int print(){
		for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++)
			cout<<maze[i][j];
		cout<<endl;
	}
	for(int i=1;i<=H;i++){
		for(int j=2;j<W;j++)
			cout<<map[i][j]<<"\t";
		cout<<endl;
	}
 } 
int main()
{
	init();
	int	iq[10000];
	int jq[10000];
	int begin=0;
	int rear=0;
	for(int i=2;i<H;i++){
		
		if(maze[i][1]==' '){
			iq[rear]=i;
			jq[rear++]=2;
			maze[i][1]='+';
			map[i][2]=1;
		}
		if(maze[i][W]==' '){
			iq[rear]=i;
			jq[rear++]=W-1;
			maze[i][W]='+';
			map[i][W-1]=1;
		}
	}
	for(int i=2;i<W;i++){
		
		if(maze[1][i]==' '){
			iq[rear]=2;
			jq[rear++]=i;
			maze[1][i]='+';
			map[2][i]=1;
		}
		if(maze[H][i]==' '){
			iq[rear]=H-1;
			jq[rear++]=i;
			maze[H][i]='+';
			map[H-1][i]=1;
		}
	}
	while(begin!=rear){
		int i=iq[begin];
		int j=jq[begin++];
		for(int z=0;z<4;z++)
			if(maze[i+x[z]][j+y[z]]==' '){
				iq[rear]=i+x[z]*2;
				jq[rear++]=j+y[z]*2;
				if(map[i+x[z]*2][j+y[z]*2]>map[i][j]+1||map[i+x[z]*2][j+y[z]*2]==0)
					map[i+x[z]*2][j+y[z]*2]=map[i][j]+1;
				maze[i+x[z]][j+y[z]]='+';
			}
	}
	int max1=0;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++)
		if(max1<map[i][j])
			max1=map[i][j];
	fout<<max1<<endl;
}

