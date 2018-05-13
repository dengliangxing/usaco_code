/*
ID: 15256292
LANG:C++
TASK:concom
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[105][105]={0};
bool con[105][105]={0};
int n,m=0;

void dfs(int i,int j)
{
    if (con[i][j]) return;      //��һ��һ��Ҫ�У���Ҫ������
    con[i][j]=true;
    for (int k=1;k<=m;k++)
    {
        a[i][k]+=a[j][k];
        if (a[i][k]>50) dfs(i,k); //��Ȼ��������Ҳ���ԣ�����Ҫ��ͬmain�����еݹ�����ҲҪ��
    }
}

int main()
{
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    int u,v,w;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>u>>v>>w;
        a[u][v]=w;
        if (u>m) m=u;
        if (v>m) m=v;
    }

    for (int i=1;i<=m;i++)  
        for (int j=1;j<=m;j++)
        if (a[i][j]>50) dfs(i,j);

    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
        if (i!=j && con[i][j]) printf("%d %d\n",i,j);

    
