/*
ID:15256292
LANG:C++
TASK:fence9
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	freopen("fence9.in","r",stdin); 
	freopen("fence9.out","w",stdout);
	int n,m,p;
	cin>>n>>m>>p;
	int sum=0;
	for(int y=1;y<m;y++){
		double min1=y*(n*1.0/m);
		if(min1==(int)min1)
			min1++;
		else
			min1=(int)(min1)+1;
		double max1=y*((n-p)*1.0/m)+p;
		if(max1==(int)max1)
			max1--;
		else
			max1=(int)max1;
		if(max1-min1+1>=0)
			sum+=max1-min1+1;
	}
	cout<<sum<<endl;
} 
