#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,M,ans1,ans2,K,x,y,z;
ll parent[1000005];
struct edges{
    ll u,v,w;
}graph[1000005],edge;

bool cmp(edges a,edges b)
{
    return (a.w<b.w);
}

ll find_root(ll p)
{
    if (parent[p]==p) return p;
    return parent[p] = find_root(parent[p]);
}

void KRUSKAL()
{
    sort(graph,graph+N+K-1,cmp);
    for (ll i=1;i<=N;i++)
        parent[i] = i;
    ans2 = 0;
    for (ll i=0;i<N+K-1;i++)
    {
        edge = graph[i];
        ll u = find_root(graph[i].u);
        ll v = find_root(graph[i].v);
        if (u!=v)
        {
            parent[u] = v;
            ans2+=graph[i].w;
        }
    }
    printf("%lld\n",ans2);
}

int main ()
{
    ll caseno = 0;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    while(scanf("%lld",&N)==1)
    {
        ///cout<<N<<endl;
        if (caseno>0)
            printf("\n");
        caseno++;
        ans1 = 0;
        for (ll i=0;i<N-1;i++)
            scanf("%lld%lld%lld",&graph[i].u,&graph[i].v,&graph[i].w),ans1+=graph[i].w;
        scanf("%lld",&K);
        for (ll i=N-1;i<(N+K-1);i++)
            scanf("%lld%lld%lld",&graph[i].u,&graph[i].v,&graph[i].w);
        scanf("%lld",&M);
        for (ll i=0;i<M;i++)
            scanf("%lld%lld%lld",&x,&y,&z);
        printf("%lld\n",ans1);
        KRUSKAL();
    }
    return 0;
}
