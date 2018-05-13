/*
ID:15256292
LANG:C++
TASK:spin
*/ 
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
ifstream fin("spin.in");
ofstream fout("spin.out"); 
int v[6];
int begin[100][100];
int l[100][100];
int wl[362];
void print(){
//	for(int i=0;i<360;i++)
//		cout<<wl[i]<<" ";
	for(int i=1;i<=5;i++)
		cout<<begin[i]<<" ";
	cout<<endl; 
}
void init(){
	for(int i=1;i<=5;i++)
		for(int j=1;j<100;j++){
			begin[i][j]=-1;
			l[i][j]=-1;
		}
}
bool f(int t){
	for(int i=1;i<=5;i++)
		for(int j=1;begin[i][j]!=-1;j++){
			int B=(begin[i][j]+v[i]*t)%360;
			for(int z=B;z<=B+l[i][j];z++)
				wl[z%360]++;
		}
//	print();
	for(int i=0;i<360;i++)
		if(wl[i]>=5)
			return true;
	memset(wl,0,sizeof(wl));
	return false;
}
int main(){
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	init();
	for(int i=1;i<=5;i++){
		cin>>v[i];
		int num;
		cin>>num;
		for(int j=1;j<=num;j++)
			cin>>begin[i][j]>>l[i][j];
	}
//	cout<<sum<<endl;
	for(int i=0;i<360;i++){
		if(f(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"none"<<endl;
	return 0;
}
