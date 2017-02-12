#include<bits/stdc++.h>
#define ll long long
#define MAX 9999999999999
using namespace std;

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    string xx;
    ll N,M,caseno=0,graph[23][23],u,v,w;
    while(scanf("%lld%lld",&N,&M) && (N>0||M>0))
    {
        for (ll i=1;i<=N;i++)
            for (ll j=1;j<=N;j++)
                graph[i][j] = MAX;
        vector<string>names;
        for (ll i=0;i<N;i++)
            cin>>xx,names.push_back(xx);
        for (ll i=0;i<M;i++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[u][v] = graph[v][u] = w;
        }
        for (ll k=1;k<=N;k++)
            for (ll i=1;i<=N;i++)
                for (ll j=1;j<=N;j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
        ll MX = MAX,ans;
        for (ll i=1;i<=N;i++)
        {
            ll sum = 0;
            for (ll j=1;j<=N;j++)
            {
                if (i!=j&&graph[i][j]!=MAX)
                    sum+=graph[i][j];
            }
            if (sum<MX)
            {
                MX = sum;
                ans = i;
            }
        }
        printf("Case #%lld : %s\n",++caseno,names[ans-1].c_str());
    }
    return 0;
}
