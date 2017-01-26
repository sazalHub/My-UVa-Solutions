#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll N,E,parent[10005];

struct position{
    double x,y;
}pos[105],P;

struct edges{
    ll u,v;
    double weight;
}graph[10005],edge;

double distances(ll i,ll j)
{
    double x = abs(pos[i].x-pos[j].x);
    double y = abs(pos[i].y-pos[j].y);
    return sqrt(x*x + y*y);
}

void sett()
{
    E = 0;
    for (ll i=1;i<=N;i++)
    {
        for (ll j=i+1;j<=N;j++)
        {
            double ret = distances(i,j);
            graph[E].u = i,graph[E].v = j,graph[E].weight = ret;
            E++;
        }
    }
}

bool cmp(edges a,edges b)
{
    return (a.weight<b.weight);
}

ll find_root(ll p)
{
    if (parent[p]==p) return p;
    return parent[p] = find_root(parent[p]);
}

void KRUSKAL()
{
    sort(graph,graph+E,cmp);
    for (ll i=1;i<=N;i++)
        parent[i] = i;
    double ans = 0.00;
    for (ll i=0;i<E;i++)
    {
        ll u = find_root(graph[i].u);
        ll v = find_root(graph[i].v);
        if (u!=v)
        {
            parent[u] = v;
            ans+=graph[i].weight;
        }
    }
    printf("%0.2lf\n",ans);
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        if (caseno>0)
            printf("\n");
        caseno++;
        scanf("%lld",&N);
        for (ll i=1;i<=N;i++)
            scanf("%lf%lf",&pos[i].x,&pos[i].y);
        sett();
        KRUSKAL();
    }
    return 0;
}
