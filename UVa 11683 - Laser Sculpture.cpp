#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll heigth,length,H,ans,pre;

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    while(scanf("%lld%lld",&heigth,&length)==2 && heigth && length)
    {
        ans = 0;
        for (ll i=1;i<=length;i++)
        {
            scanf("%lld",&H);
            if (i==1)
                ans = heigth - H;
            else if (H<pre)
                ans = ans + (pre-H);
            pre = H;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
