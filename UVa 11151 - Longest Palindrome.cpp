#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1001][1001],len,ans;
char str[1005];

ll solve(ll i,ll j)
{
    if (i==j) return 1;
    if (i>j) return 0;
    if (dp[i][j]!=-1) return dp[i][j];
    if (str[i]==str[j])
        return dp[i][j] = 2 + solve(i+1,j-1);
    else
        return dp[i][j] = max(solve(i+1,j),solve(i,j-1));
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases;
    scanf("%lld",&cases);
    getchar();
    while(cases--)
    {
        gets(str);
        len = strlen(str);
        if (len==0)
        {
            printf("0\n");
            continue;
        }
        for (ll i=0;i<=len;i++)
            for (ll j=0;j<=len;j++)
                dp[i][j] = -1;
        ans = solve(0,len-1);
        printf("%lld\n",ans);
    }
    return 0;
}
