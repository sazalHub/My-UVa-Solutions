#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll V,R,x,y,E,states;
double rails,roads;
ll parent[1005];

struct position{
    ll x,y;
}P,cord[1005];

struct edges{
    ll u,v;
    double weight;
}graph[1000005],edge;

double distances(ll i,ll j)
{
    ll x = abs(cord[i].x-cord[j].x);
    ll y = abs(cord[i].y-cord[j].y);
    return sqrt(x*x*1.0 + y*y*1.0);
}

void sett(ll i)
{
    for (ll j=0;j<i;j++)
    {
        double w = distances(j,i);
        graph[E].u = i;
        graph[E].v = j;
        graph[E].weight = w;
        E++;
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
    for (ll i=0;i<V;i++) parent[i] = i;
    states = V,rails = 0.00,roads = 0.00;
    for (ll i=0;i<E;i++)
    {
        ll u = find_root(graph[i].u);
        ll v = find_root(graph[i].v);
        if (u!=v)
        {
            parent[u] = v;
            if (graph[i].weight<=(double)R)
                roads+=graph[i].weight,states--;
            else
                rails+=graph[i].weight;
        }
    }
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&V,&R);
        E = 0;
        for (ll i=0;i<V;i++)
        {
            scanf("%lld%lld",&cord[i].x,&cord[i].y);
            sett(i);
        }
        KRUSKAL();
        printf("Case #%lld: %lld %lld %lld\n",++caseno,(ll)round(states),(ll)round(roads),(ll)round(rails));
    }
    return 0;
}
