/*
ID:15256292
LANG:C++
TASK:kimbits

*/ 
#include <stdio.h>  
#define maxn 100  
long long f[maxn][maxn];//f[i][j]长度为I，最多J个1   
long long n,l,t;
void print(int t,int i,int j){
	if(i==0)
		return;
	if(f[i-1][j]<t){
		printf("1");
		print(t-f[i-1][j],i-1,j-1);
	}
	else{
		printf("0");
		print(t,i-1,j);
	}
}
int main()  
{  
    freopen("kimbits.in","r",stdin);  
    freopen("kimbits.out","w",stdout);  
      
    scanf("%lld%lld%lld",&n,&l,&t);  
      
    for (int i=0;i<=n;++i) f[i][0]=f[0][i]=1;  
    for (int i=1;i<=n;++i)  
        for (int j=1;j<=n;++j)  
            f[i][j]=f[i-1][j]+f[i-1][j-1];  
      
    for (int i=n;i>=1;--i)  
        if (t>f[i-1][l])  
        {  
                      printf("1");  
                      t-=f[i-1][l];  
                      --l;  
        }  
        else printf("0");
//	print(t,n,l);  
    printf("\n");  
      
    return 0;  
}  
