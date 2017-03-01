#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct value{
    ll x;
    value(){}
    value(ll a){x=a;}
};

bool operator<(value a,value b)
{
    return (a.x>b.x);
}

int main ()
{
    priority_queue<value>Q;
    value a,b;
    ll N,arr[5005],num,sum;
    while(scanf("%lld",&N)==1&&N)
    {
        for (ll i=0;i<N;i++)
        {
            scanf("%lld",&num);
            Q.push(value(num));
        }
        sum = 0;
        while(Q.size()!=1)
        {
            a = Q.top(),Q.pop();
            b = Q.top(),Q.pop();
            sum+=(a.x+b.x);
            Q.push(value(a.x+b.x));
        }
        printf("%lld\n",sum);
        Q.pop();
    }
    return 0;
}

