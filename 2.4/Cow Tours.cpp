/*
ID:15256292
LANG:C++
TASK:cowtour
*/ 
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define NMAX 151
#define z 1E-8
#define INF 9999999
using namespace std;
struct point
{
    int x;
    int y;
};

int n;
point p[NMAX];
double dd[NMAX][NMAX];

double distant(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double diameter(int x)
{
    double maxi=0;
    for(int i=0;i<n;i++)
    {
        if(i==x)continue;
        if(abs(dd[x][i]-INF)>z&&dd[x][i]>maxi)
            maxi=dd[x][i];
    }
    return maxi;
}

void test()
{    
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
        //cout<<p[i].x<<" "<<p[i].y<<endl;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dd[i][j]=INF;
    char c;
    for(int i=0;i<n;i++)
    {
        getchar();
        for(int j=0;j<n;j++)
        {
            fscanf(stdin,"%c",&c);
            if(c=='1')
            {
                dd[i][j]=distant(p[i],p[j]);
                dd[j][i]=dd[i][j];
            }
            //cout<<c;
            //if(j==n-1)cout<<endl;
        }
    }

    for (int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if( dd[i][k]+dd[k][j]<dd[i][j])
                {
                    dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
                    dd[j][i]=dd[i][j];
                }
            }

    double maxi=INF;
    double temp;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)        
            if(abs(dd[i][j]-INF)<z &&i!=j)
            {
                temp=distant(p[i],p[j]) + diameter(i)+diameter(j);
                if(temp<maxi)maxi=temp;
            }

    for(int i=0;i<n;i++)
        if(diameter(i)>maxi)maxi=diameter(i);
    printf("%.6lf\n",maxi);
}

int main () 
{        
    test();        
    return 0;
}
