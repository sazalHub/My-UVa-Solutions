#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll V,E,u,v;
vector<ll>graph[100010];
bool vis[100010];
stack<ll>topsort;

void DFS(ll u)
{
    vis[u] = true;
    ll len = graph[u].size();
    for (ll i=0;i<len;i++)
    {
        v = graph[u][i];
        if (!vis[v])
            DFS(v);
    }
    topsort.push(u);
}

void DFS1(ll u)
{
    vis[u] = true;
    ll len = graph[u].size();
    for (ll i=0;i<len;i++)
    {
        v = graph[u][i];
        if (!vis[v])
            DFS1(v);
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,cnt,caseno=0;
    scanf("%lld",&cases);
    ///cout<<cases<<endl;
    while(cases--)
    {
        scanf("%lld%lld",&V,&E);

        for (ll i=0;i<E;i++)
        {
            scanf("%lld%lld",&u,&v);
            graph[u].push_back(v);
        }
        ///cout<<1<<endl;

        memset(vis,false,sizeof(vis));
        for (ll i=1;i<=V;i++)
        {
            if (!vis[i])
                DFS(i);
        }
        ///cout<<2<<endl;

        cnt = 0;
        memset(vis,false,sizeof(vis));
        while(!topsort.empty())
        {
            u = topsort.top();
            topsort.pop();
            if (!vis[u])
                DFS1(u),cnt++;
        }
        ///cout<<3<<endl;

        printf("%lld\n",cnt);

        for (ll i=1;i<=V;i++)
            graph[i].clear();
    }
    return 0;
}
