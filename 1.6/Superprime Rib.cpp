/*
ID: 15256292
LANG: C++ 
TASK: sprime
*/
#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
int N;
ifstream fin("sprime.in");
ofstream fout("sprime.out");
int num1[]={2,3,5,7};
int num2[]={1,3,7,9};
bool isPrime(long num)
{
	for(int i=2;i<=sqrt(num);i++)
	if(num%i==0)
		return false;
		return true;
 } 
void DFS(int n,int st)
{
	if(n==N)
	{
		fout<<st<<endl;
		return ;
	}
	for(int i=0;i<4;i++)
		if(isPrime(st*10+num2[i]))
			DFS(n+1,st*10+num2[i]);
}
int main()
{
	fin>>N;
	for(int i=0;i<4;i++)
	DFS(1,num1[i]);
	return 0;
}
