#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,P[1005],W[10005],G,GM[105],MX,dp[1005][35],ans;

int main ()
{
    ll cases;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld",&N);
        for (ll i=1;i<=N;i++)
            scanf("%lld%lld",&P[i],&W[i]);
        scanf("%lld",&G);
        MX = 0;
        for (ll i=1;i<=G;i++)
            scanf("%lld",&GM[i]),MX = max(MX,GM[i]);
        memset(dp,0,sizeof(dp));
        for (ll i=1;i<=N;i++)
        {
            for (ll j=1;j<=MX;j++)
            {
                if (j<W[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-W[i]]+P[i]);
            }
        }
        ///cout<<1<<endl;
        ans = 0;
        for (ll i=1;i<=G;i++)
            ans+=dp[N][GM[i]];
        printf("%lld\n",ans);
    }
    return 0;
}
