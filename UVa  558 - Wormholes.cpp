#include<bits/stdc++.h>
#define ll long long
#define MAX 9999999999999999
using namespace std;

ll V,E,dist[1005];

struct EDGES{
    ll from,to,cost;
}edges[2005],node;

int main ()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    ll cases,caseno=0;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld%lld",&V,&E);

        for (int i=0;i<E;i++)
            scanf("%lld%lld%lld",&edges[i].from,&edges[i].to,&edges[i].cost);

        for (int i=0;i<=V;i++)
            dist[i] = MAX;
        dist[0] = 0;

        for (int i=0;i<V-1;i++)
        {
            for (int j=0;j<E;j++)
            {
                node = edges[j];
                if (dist[node.from]+node.cost<dist[node.to])
                    dist[node.to] = dist[node.from]+node.cost;
            }
        }

        bool flag = true;
        for (int j=0;j<E && flag;j++)
        {
            node = edges[j];
            if (dist[node.from]+node.cost<dist[node.to])
                flag = false;
        }

        ///printf("Case %lld: ",++caseno);
        if (flag)
            printf("not possible\n");
        else
            printf("possible\n");
    }
    return 0;
}
