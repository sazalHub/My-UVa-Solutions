#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[46355];
vector<ll>primes;

void seive()
{
    primes.push_back(2);
    for (ll i=3;i<46350;i+=2)
    {
        if (!vis[i])
        {
            primes.push_back(i);
            for (ll j=i*i;j<46350;j+=2*i)
                vis[j] = true;
        }
    }
}

int main ()
{
    seive();
    ll N;
    while(scanf("%lld",&N) && N!=0)
    {
        vector<ll>factors;
        ll tmp = N;
        if (N<0)
            factors.push_back(-1),N*=-1;
        for (ll i=0;primes[i]*primes[i]<=N;i++)
        {
            while(N%primes[i]==0)
            {
                factors.push_back(primes[i]);
                N/=primes[i];
            }
        }
        if (N>1)
            factors.push_back(N);
        ll len = factors.size();
        printf("%lld =",tmp);
        for (ll i=0;i<len;i++)
        {
            printf(" %lld",factors[i]);
            if (i<len-1)
                printf(" x");
        }
        printf("\n");
    }
    return 0;
}

