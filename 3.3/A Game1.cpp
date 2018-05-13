/*
ID:15256292
LANG:C++
TASK:game1
*/ 
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n, num[110], dp[110][110], sum[110][110];
int main()
{
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &num[i]);
    for(int i=1; i<=n; i++)
    {
        sum[i][i] = num[i];
        for(int j=i+1; j<=n; j++)
            sum[i][j] = sum[i][j-1]+num[j];
    }
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++)
        dp[i][i] = num[i];
    for(int l=1; l<n; l++)
        for(int i=1; i<=n-l; i++)
            dp[i][i+l] = sum[i][i+l]-min(dp[i][i+l-1], dp[i+1][i+l]);
    printf("%d %d\n", dp[1][n], sum[1][n]-dp[1][n]);
    return 0;
}
