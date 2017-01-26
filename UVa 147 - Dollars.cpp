#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,n;
ll arr[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[30555][15];

ll solve(ll i,ll V)
{
    ///cout<<i<<" "<<V<<endl;
    if (V==0)
    {
        ///cout<<11<<endl;
        return 1;
    }
    if (i>10)
    {
        if (V==0)
        {
            ///cout<<22<<endl;
            return 1;
        }
        else
            return 0;
    }
    if (dp[V][i]!=-1)
    {
        ///cout<<33<<endl;
        return dp[V][i];
    }
    ll ret1 = 0,ret2 = 0;
    if (V-arr[i]>=0)
        ret1 = solve(i,V-arr[i]);
    ret2 = solve(i+1,V);
    return dp[V][i] = ret1 + ret2;
}

int main ()
{
    memset(dp,-1,sizeof(dp));
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%lld.%lld",&N,&n)==2)
    {
        ll Total = N*100+n;
        if (Total==0)
            break;
        ll ans = solve(0,Total);
        printf("%3lld.%.2lld%17lld\n",N,n,ans);
    }
    return 0;
}
