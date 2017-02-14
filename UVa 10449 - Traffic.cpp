#include<bits/stdc++.h>
#define ll long long
#define MAX 99999999999999
using namespace std;

struct EDGES{
    ll from,to,cost;
}way;
ll dis,V,busy[202],dist[202],Q,E,X;

int main ()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll caseno = 0;
    while(scanf("%lld",&V)==1)
    {
        for (ll i=1;i<=V;i++)
            scanf("%lld",&busy[i]),dist[i] = MAX;

        scanf("%lld",&E);
        EDGES edges[E+5];
        for (ll i=0;i<E;i++)
        {
            scanf("%lld%lld",&edges[i].from,&edges[i].to);
            dis = busy[edges[i].to] - busy[edges[i].from];
            edges[i].cost = dis*dis*dis;
        }

        dist[1]=0;
        for (ll i=0;i<V-1;i++)
        {
            for (ll j=0;j<E;j++)
            {
                way = edges[j];
                if (dist[way.from]+way.cost<dist[way.to]&&dist[way.from]!=MAX)
                    dist[way.to] = dist[way.from]+way.cost;
            }
        }

        for (ll j=0;j<E;j++)
        {
            way = edges[j];
            if (dist[way.from]+way.cost<dist[way.to]&&dist[way.from]!=MAX)
                dist[way.to] = -MAX;
        }

        printf("Set #%lld\n",++caseno);
        scanf("%lld",&Q);
        for (ll i=0;i<Q;i++)
        {
            scanf("%lld",&X);
            if (dist[X]<3||dist[X]==MAX)
                printf("?\n");
            else
                printf("%lld\n",dist[X]);
        }
    }
    return 0;
}
