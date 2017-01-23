#include<bits/stdc++.h>
#define ll long long
using namespace std;
char str[1000005];

bool check(ll mod)
{
    ll ret = 0;
    for (ll i=0;str[i];i++)
        ret = (ret*10 + (str[i]-48))%mod;
    if (ret==0) return true;
    return false;
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll caseno=0,len;
    while(scanf("%s",&str)==1)
    {
        if (caseno>0)
            printf("\n");
        caseno++;

        bool mod4 = check(4);
        bool mod100 = check(100);
        bool mod400 = check(400);
        bool mod15 = check(15);
        bool mod55 = check(55);

        bool lp = false,hf = false,bf = false;
        if (mod400||(mod4&&!mod100)) lp = true;
        if (mod15) hf = true;
        if (lp&&mod55) bf = true;
        ///cout<<str<<endl;
        ///cout<<lp<<endl;
        if (!lp && !hf && !bf)
        {
            printf("This is an ordinary year.\n");
            continue;
        }
        if (lp)
            printf("This is leap year.\n");
        if (hf)
            printf("This is huluculu festival year.\n");
        if (lp&&bf)
            printf("This is bulukulu festival year.\n");
    }
    return 0;
}
