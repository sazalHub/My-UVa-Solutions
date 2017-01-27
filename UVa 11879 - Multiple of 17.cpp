#include<bits/stdc++.h>
#define ll long long
#define MOD 17
using namespace std;
int main ()
{
    string xx;
    while(cin>>xx&&xx[0]!='0')
    {
        ll rem = 0;
        for (ll i=0;xx[i];i++)
            rem =  (rem*10+(xx[i]-48))%MOD;
        if (rem==0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
