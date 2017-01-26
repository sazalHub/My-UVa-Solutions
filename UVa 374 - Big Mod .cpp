#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ret,y;
ll mod(ll B,ll P,ll M)
{
    if (P==0)
        return 1;
    else if (P%2==0)
    {
        y=mod(B,P/2,M);
        ret=(y%M*y%M)%M;
    }
    else
    {
        y=mod(B,P/2,M);
        ret=((B%M*(y%M*y%M))%M)%M;
    }
    return ret;
}
int main ()
{
    ll B,P,M,ans;
    while(cin>>B>>P>>M)
    {
        ans=mod(B,P,M);
        cout<<ans%M<<endl;
    }
    return 0;
}
