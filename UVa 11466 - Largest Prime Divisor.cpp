#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[10001005];
vector<ll>primes;
ll len;

void PrimeGenerator()
{
    primes.push_back(2);
    ll lmt = sqrt(10000005);
    for (ll i=3;i<=lmt;i+=2)
    {
        if (!vis[i])
        {
            primes.push_back(i);
            for (ll j=i*i;j<=10000005;j+=2*i)
                vis[j] = true;
        }
    }
    if (lmt%2==0)
        lmt++;
    if (vis[lmt])
        lmt+=2;
    for (ll i=lmt;i<=10000005;i+=2)
        if (!vis[i])
            primes.push_back(i);
    len = primes.size();
}

int main ()
{
    PrimeGenerator();
    ll N;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    while(scanf("%lld",&N)&&N)
    {
        if (N<0)
            N*=-1;
        ll cnt = 0,ans = 0;
        for (ll i=0;primes[i]<=N && i<len;i++)
        {
            if (N%primes[i]==0)
            {
                ans = primes[i];
                cnt++;
                while(N%primes[i]==0)
                    N/=primes[i];
            }
        }
        if (N>1)
            ans = N,cnt++;
        if (cnt<=1)
            ans = -1;
        printf("%lld\n",ans);
    }
    return 0;
}
