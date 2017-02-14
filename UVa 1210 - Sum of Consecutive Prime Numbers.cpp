#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>primes;
ll len;
bool visited[10050];

void PrimeGenerator()
{
    primes.push_back(2);
    for (ll i=4;i<=10020;i+=2) visited[i] = true;
    for (ll i=3;i<=10020;i+=2)
    {
        if (!visited[i])
        {
            primes.push_back(i);
            for (ll j=i*i;j<=10020;j+=2*i)
                visited[j] = true;
        }
    }
    len = primes.size();
    ///cout<<primes[len-1]<<endl;
}

int main ()
{
    PrimeGenerator();
    ll N,sum,cnt;
    while(scanf("%lld",&N)&&N)
    {
        cnt = 0;
        for (ll i=0;primes[i]<=N;i++)
        {
            sum = primes[i];
            for (ll j=i+1;sum<N;j++)
                sum+=primes[j];
            if (sum==N)
                cnt++;
        }
        printf("%lld\n",cnt);
    }
    return 0;
}


