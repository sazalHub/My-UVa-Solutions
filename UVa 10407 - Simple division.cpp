#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
    return (a%b)?gcd(b,a%b):b;
}

int main ()
{
    ll arr[1005],N,num;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    while(scanf("%lld",&arr[0])&&arr[0])
    {
        map<ll,bool>vis;
        vis[arr[0]]=true;
        N = 1;
        for (ll i;;i++)
        {
            scanf("%lld",&num);
            if (num==0)
                break;
            if (vis[num])
                continue;
            vis[num]=true;
            arr[N++]=num;
        }
        vector<ll>diff;
        sort(arr,arr+N);
        for (ll i=N-1;i>=0;i--)
        {
            for (ll j=i-1;j>=0;j--)
            {
                ll dif = arr[i] - arr[j];
                diff.push_back(dif);
            }
        }
        ll ans = diff[0];
        ll len = diff.size();
        for (ll i=1;i<len;i++)
            ans = gcd(ans,diff[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
