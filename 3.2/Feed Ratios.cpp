/*
ID:15256292
LANG:C++
TASK:ratios
*/ 
#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
int min1,min2,min3;
int minn=303;
int r[4][4];
int main(){
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	for(int i=0;i<4;i++)
		for(int j=1;j<=3;j++)
			cin>>r[i][j];
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			for(int z=0;z<=100;z++)
				if((r[1][1]*i+r[2][1]*j+r[3][1]*z)*r[0][2]==(r[1][2]*i+r[2][2]*j+r[3][2]*z)*r[0][1]&&(r[1][1]*i+r[2][1]*j+r[3][1]*z)>=r[0][1])
					if((r[1][2]*i+r[2][2]*j+r[3][2]*z)*r[0][3]==(r[1][3]*i+r[2][3]*j+r[3][3]*z)*r[0][2])
					{
						if(minn>i+j+z&&i+j+z!=0){
							min1=i;
							min2=j;
							min3=z;
							minn=i+j+z;
						}
					}
	if(minn!=303){
		cout<<min1<<" "<<min2<<" "<<min3<<" "<<(min1*r[1][1]+min2*r[2][1]+min3*r[3][1])/r[0][1]<<endl;
		return 0;
	} 
	cout<<"NONE"<<endl;
	return 0;
}
