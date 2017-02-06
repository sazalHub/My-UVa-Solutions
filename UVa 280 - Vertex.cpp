#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,vector<ll> >graph;
bool visited[101];
ll V,N,X,Y,len;

void BFS(ll start)
{
    memset(visited,false,sizeof(visited));
    queue<ll>Q;
    Q.push(start);
    while(!Q.empty())
    {
        ll u = Q.front();
        Q.pop();
        len = graph[u].size();
        for (ll i=0;i<len;i++)
        {
            ll v = graph[u][i];
            if (!visited[v])
            {
                visited[v] = true;
                Q.push(v);
            }
        }
    }
    ll cnt = 0;
    for (ll i=1;i<=V;i++)
        if (!visited[i])
            cnt++;
    printf("%lld",cnt);
    for (ll i=1;i<=V;i++)
        if (!visited[i])
            printf(" %lld",i);
    printf("\n");
}

int main ()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    while(scanf("%lld",&V)==1 && V)
    {
        graph.clear();
        while(scanf("%lld",&X)==1 && X)
        {
            while(scanf("%lld",&Y)==1 && Y)
            {
                graph[X].push_back(Y);
            }
        }
        scanf("%lld",&N);
        for (ll i=0;i<N;i++)
        {
            scanf("%lld",&X);
            BFS(X);
        }
    }
    return 0;
}
