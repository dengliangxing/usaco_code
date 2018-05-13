#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct pointer{
	int i,j;
};
struct Q{
	int i,j;
};
pointer people[1041];
int map[1041][41][27];
int minmap[41][27];
int R,C;
int sumpeople=0;
int cI[]={-2,-1,1,2,2,1,-1,-2};
int cJ[]={1,2,2,1,-1,-2,-2,-1};
void init(){
	for(int i=0;i<=1040;i++)
		for(int j=1;j<=40;j++)
			for(int z=1;z<=26;z++)
				map[i][j][z]=-1;
	int r,c;
	Q queue[1043];
	int start=0,rear=0;
	cin>>R>>C;
	while(cin>>r>>c){
		people[sumpeople].j=r-'A'+1;
		people[sumpeople++].i=c;
	}
	for(int i=0;i<sumpeople;i++){
		int I,J;
		queue[rear].i=people[i].i;
		queue[rear++].j=people[i].j;
		map[i][I][J]=0;
		while(start!=rear){
			I=queue[start].i;
			J=queue[start++].j;
			for(int j=0;j<8;j++){
				if(I+cI[j]<=C&&J+cJ[j]<=R&&map[i][I+cI[j]][J+cJ[j]]==-1){
					map[i][I+cI[j]][J+cJ[j]]=map[i][I][J]+1;
					queue[rear].i=I+cI[j];
					queue[rear++].j=J+cJ[j];	
				}
			}
		}	 
	}	
}
int main(){
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	init();
	for(int i = 1;i<=C;i++){
		for(int j=1;j<=R;j++)
			cout<<map[0][i][j]<<"\t";
		cout<<endl;
	}
}
