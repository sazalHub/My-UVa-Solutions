#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ll sum = 0;
    ll arr[110];
    arr[0] = 0;
    for (ll i=1;i<=105;i++)
    {
        ll tsum=1;
        for (ll j=0;j<i;j++)
            tsum = (tsum%10 * i%10)%10;
        sum=(sum+tsum)%10;
        arr[i]=sum;
        ///cout<<i<<" "<<sum<<endl;
    }
    char str[2005];
    ll len,ind;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    while(scanf("%s",&str)&&str[0]!='0')
    {
        len = strlen(str);
        if (len==1)
            ind = str[0]-48;
        else
            ind = (str[len-2]-48)*10 + (str[len-1]-48);
        printf("%lld\n",arr[ind]);
    }
    return 0;
}
