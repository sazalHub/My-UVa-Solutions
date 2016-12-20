#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct data {
    ll gave,earn;
};

int main ()
{
    ll n,k=0;
    while(scanf("%lld",&n)==1)
    {
        if (k>0)
            cout<<endl;
        k++;
        map<string,data>names;
        vector<string>nmes;
        for (ll i=0;i<n;i++)
        {
            string x;
            cin>>x;
            nmes.push_back(x);
            data pt;
            pt.gave=0;
            pt.earn=0;
            names[x]=pt;
        }

        for (ll j=0;j<n;j++)
        {
            string nme;
            ll amount,num;
            cin>>nme>>amount>>num;
            if (num==0)
                continue;
            ll give_per_person = amount/num;
            names[nme].gave+=give_per_person*num;
            for (ll i=0;i<num;i++)
            {
                string x;
                cin>>x;
                names[x].earn+=give_per_person;
            }
        }

        ll sze = nmes.size();
        for (ll i=0;i<sze;i++)
        {
            string x=nmes[i];
            ll ans = names[x].earn - names[x].gave;
            cout<<x<<" "<<ans<<endl;
        }
        nmes.clear();
        names.clear();
    }
    return 0;
}
